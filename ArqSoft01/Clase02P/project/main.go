package main

import "fmt"

func Suma(nums ...int) int {
	suma := 0
	for _, x := range nums {
		suma += x
	}
	return suma
}

func main() {
	fmt.Println("Hola mundo!")

	fmt.Println(Suma(1, 2, 3, 4, 5))
}
