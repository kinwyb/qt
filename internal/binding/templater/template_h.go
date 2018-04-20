package templater

import (
	"bytes"
	"fmt"
	"strings"

	"github.com/therecipe/qt/internal/binding/parser"
	"github.com/therecipe/qt/internal/utils"
)

func HTemplate(m string, mode int, tags string) []byte {
	utils.Log.WithField("module", m).Debug("generating h")

	var bb = new(bytes.Buffer)
	defer bb.Reset()

	if m != parser.MOC {
		m = "Qt" + m
	}

	//header
	fmt.Fprintf(bb, "%v\n\n", buildTags(m, false, mode, tags))

	fmt.Fprint(bb, "#pragma once\n\n")

	fmt.Fprintf(bb, "#ifndef GO_%v_H\n", strings.ToUpper(m))
	fmt.Fprintf(bb, "#define GO_%v_H\n\n", strings.ToUpper(m))

	fmt.Fprint(bb, "#include <stdint.h>\n\n")

	fmt.Fprint(bb, "#ifdef __cplusplus\n")
	for _, c := range parser.SortedClassNamesForModule(m, true) {
		if parser.State.ClassMap[c].IsSubClassOfQObject() {
			if m == parser.MOC {
				fmt.Fprintf(bb, "class %v;\n", c)
				fmt.Fprintf(bb, "void %[1]v_%[1]v_QRegisterMetaTypes();\n", c)
			} else {
				fmt.Fprintf(bb, "int %[1]v_%[1]v_QRegisterMetaType();\n", c)
			}
		}
	}
	fmt.Fprint(bb, "extern \"C\" {\n#endif\n\n")

	fmt.Fprintf(bb, "struct %v_PackedString { char* data; long long len; };\n", strings.Title(m))
	fmt.Fprintf(bb, "struct %v_PackedList { void* data; long long len; };\n", strings.Title(m))

	//body
	for _, c := range parser.SortedClassesForModule(m, true) {
		cTemplate(bb, c, cppEnumHeader, cppFunctionHeader, ";\n", false)
	}

	//footer
	fmt.Fprint(bb, "\n#ifdef __cplusplus\n}\n#endif\n\n#endif")

	//TODO: regexp
	if mode == MOC {
		pre := bb.String()
		bb.Reset()
		libsm := make(map[string]struct{}, 0)
		for _, c := range parser.State.ClassMap {
			if c.Pkg != "" && c.IsSubClassOfQObject() {
				libsm[c.Module] = struct{}{}
			}
		}

		var libs []string
		for k := range libsm {
			libs = append(libs, k)
		}
		libs = append(libs, m)

		for _, c := range parser.SortedClassesForModule(strings.Join(libs, ","), true) {
			hName := c.Hash()
			sep := []string{" ", "\t", "\n", "\r", "(", ")", ":", ";", "*", "<", ">", "&", "~", "{", "}", "[", "]", "_", "callback"}
			for _, p := range sep {
				for _, s := range sep {
					if s == "callback" {
						continue
					}
					pre = strings.Replace(pre, p+c.Name+s, p+c.Name+hName+s, -1)
				}
			}
		}
		bb.WriteString(pre)
	}

	return bb.Bytes()
}
