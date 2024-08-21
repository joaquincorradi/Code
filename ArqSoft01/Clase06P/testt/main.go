package testt

import "fmt"

type Printer interface {
	Hello() string
}

type NoPrinter struct {
}

type ParamPrinter struct {
	Message string
}

func (r ParamPrinter) Hello() string {
	return r.Message
}

func (r NoPrinter) Hello() string {
	return "fijo"
}

func main() {
	r := ParamPrinter{}
	n := NoPrinter{}
	r.Message = "Hello no fijo"
	fmt.Println(r.Hello())
	fmt.Println(n.Hello())
}
