package main

import (
	"github.com/therecipe/qt/charts"
	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
)

type Chart struct {
	core.QObject
	*charts.QChart //TODO: directly subclass QChart instead

	_ func() `constructor:"init"`

	_ func() `slot:"handleTimeout,<-(this.m_timer.timeout)"`

	m_timer  *core.QTimer
	m_series *charts.QSplineSeries
	m_titles []string
	m_axis   *charts.QValueAxis
	m_step   float64
	m_x      float64
	m_y      float64
}

func (c *Chart) init() {
	c.QChart = charts.NewQChart(nil, 0)
	c.m_timer = core.NewQTimer(nil)
	c.m_timer.SetInterval(1000)
	c.m_axis = charts.NewQValueAxis(nil)
	c.m_x = 5
	c.m_y = 1

	c.m_series = charts.NewQSplineSeries(c)
	green := gui.NewQPen3(gui.NewQColor2(core.Qt__red))
	green.SetWidth(3)
	c.m_series.SetPen(green)
	c.m_series.Append(c.m_x, c.m_y)

	c.AddSeries(c.m_series)
	c.CreateDefaultAxes()
	c.SetAxisX(c.m_axis, c.m_series)
	c.AxisX(nil).SetRange(core.NewQVariant12(0), core.NewQVariant12(10))
	c.AxisY(nil).SetRange(core.NewQVariant12(-5), core.NewQVariant12(10))

	c.m_timer.Start2()
}

func (c *Chart) handleTimeout() {
	x := c.PlotArea().Width() / float64(c.m_axis.TickCount())
	y := (c.m_axis.Max() - c.m_axis.Min()) / float64(c.m_axis.TickCount())
	c.m_x += y
	c.m_y = core.QRandomGenerator_Global().Bounded(5) - 2.5
	c.m_series.Append(c.m_x, c.m_y)
	c.Scroll(x, 0)
	if c.m_x >= 1000 {
		c.m_timer.Stop()
	}
}
