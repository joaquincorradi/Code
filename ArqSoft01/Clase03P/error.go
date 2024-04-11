package main

import (
	"errors"
	"fmt"
)

func dividir(a, b int) (int, error) {
	if b == 0 {
		return -1, errors.New("No se puede dividir por cero.")
	}
	return a / b, nil
}

func main() {
	div, err := dividir(7, 0)
	if err != nil {
		fmt.Println("Error: ", err.Error())
		return
	}
	fmt.Println("Division: ", div)
}
