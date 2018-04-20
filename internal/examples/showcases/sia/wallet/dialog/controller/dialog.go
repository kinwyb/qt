package controller

import (
	"errors"
	"fmt"
	"math/big"
	"net/http"
	"strings"

	"github.com/therecipe/qt/core"

	"github.com/NebulousLabs/Sia/node/api"
	"github.com/NebulousLabs/Sia/types"

	maincontroller "github.com/therecipe/qt/internal/examples/showcases/sia/controller"
	_ "github.com/therecipe/qt/internal/examples/showcases/sia/view/controller"
)

var Controller *dialogController

type dialogController struct {
	core.QObject

	_ func() `constructor:"init"`

	_ func(cident string) `signal:"show"`
	_ func(bool)          `signal:"blur,->(controller.Controller)"`

	_ func(password string) *core.QVariant     `slot:"unlock,auto"`
	_ func() string                            `slot:"receive,auto"`
	_ func(amount, dest string) *core.QVariant `slot:"send,auto"`
	_ func(seed string) *core.QVariant         `slot:"recover,auto"`

	_ func() bool `slot:"isLocked,->(maincontroller.Controller)"`
}

func (c *dialogController) init() {
	Controller = c
}

func (c *dialogController) receive() string {
	wag, err := maincontroller.Client.WalletAddressGet()
	if err != nil {
		println(err.Error())
		return fmt.Sprintf("Could not get address: %v", err.Error())
	}
	return wag.Address.String()
}

func (c *dialogController) send(amount, dest string) *core.QVariant {
	if !strings.HasSuffix(amount, "SC") {
		amount += "SC"
	}

	hastings, errC := parseCurrency(amount)
	if errC != nil {
		println(errC.Error())
		return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(false), core.NewQVariant14(fmt.Sprintf("Could not parse amount: %v", errC.Error()))})
	}

	b, _ := new(big.Int).SetString(hastings, 10)
	var destH types.UnlockHash
	destH.LoadString(dest)
	_, errW := maincontroller.Client.WalletSiacoinsPost(types.NewCurrency(b), destH)
	if errW != nil {
		println(errW.Error())
		return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(false), core.NewQVariant14(fmt.Sprintf("Could not send siacoins: %v", errW.Error()))})
	}

	return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(true), core.NewQVariant14(fmt.Sprintf("Sent %s hastings to %s\n", hastings, dest))})
}

func (c *dialogController) unlock(password string) *core.QVariant {
	err := maincontroller.Client.WalletUnlockPost(password)
	if err != nil {
		println(err.Error())
		return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(false), core.NewQVariant14(fmt.Sprintf("Could not unlock your wallet: %v", err.Error()))})
	}

	maincontroller.Controller.SetLocked(false)
	return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(true)})
}

func (c *dialogController) recover(seed string) *core.QVariant {
	var swp api.WalletSweepPOST
	req, _ := maincontroller.Client.NewRequest("POST", "/wallet/sweep/seed", strings.NewReader(fmt.Sprintf("seed=%s&dictionary=%s", seed, "english"))) //TODO:
	res, err := http.DefaultClient.Do(req)
	if err != nil {
		println(err.Error())
		return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(false), core.NewQVariant14(fmt.Sprintf("Could not sweep seed: %v", err.Error()))})
	}
	res.Body.Close()
	return core.NewQVariant24([]*core.QVariant{core.NewQVariant11(true), core.NewQVariant14(fmt.Sprintf("Swept %v and %v SF from seed.", currencyUnits(swp.Coins), swp.Funds))})
}

// currencyUnits converts a types.Currency to a string with human-readable
// units. The unit used will be the largest unit that results in a value
// greater than 1. The value is rounded to 4 significant digits.
func currencyUnits(c types.Currency) string {
	pico := types.SiacoinPrecision.Div64(1e12)
	if c.Cmp(pico) < 0 {
		return c.String() + " H"
	}

	// iterate until we find a unit greater than c
	mag := pico
	unit := ""
	for _, unit = range []string{"pS", "nS", "uS", "mS", "SC", "KS", "MS", "GS", "TS"} {
		if c.Cmp(mag.Mul64(1e3)) < 0 {
			break
		} else if unit != "TS" {
			// don't want to perform this multiply on the last iter; that
			// would give us 1.235 TS instead of 1235 TS
			mag = mag.Mul64(1e3)
		}
	}

	num := new(big.Rat).SetInt(c.Big())
	denom := new(big.Rat).SetInt(mag.Big())
	res, _ := new(big.Rat).Mul(num, denom.Inv(denom)).Float64()

	return fmt.Sprintf("%.4g %s", res, unit)
}

// parseCurrency converts a siacoin amount to base units.
func parseCurrency(amount string) (string, error) {
	units := []string{"pS", "nS", "uS", "mS", "SC", "KS", "MS", "GS", "TS"}
	for i, unit := range units {
		if strings.HasSuffix(amount, unit) {
			// scan into big.Rat
			r, ok := new(big.Rat).SetString(strings.TrimSuffix(amount, unit))
			if !ok {
				return "", errors.New("malformed amount")
			}
			// convert units
			exp := 24 + 3*(int64(i)-4)
			mag := new(big.Int).Exp(big.NewInt(10), big.NewInt(exp), nil)
			r.Mul(r, new(big.Rat).SetInt(mag))
			// r must be an integer at this point
			if !r.IsInt() {
				return "", errors.New("non-integer number of hastings")
			}
			return r.RatString(), nil
		}
	}
	// check for hastings separately
	if strings.HasSuffix(amount, "H") {
		return strings.TrimSuffix(amount, "H"), nil
	}

	return "", errors.New("amount is missing units; run 'wallet --help' for a list of units")
}
