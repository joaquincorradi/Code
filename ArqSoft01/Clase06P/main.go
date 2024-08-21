package main

import (
	"fmt"

	"package_a/package_a"
	"package_b/package_b"
)

func main() {
	fmt.Println(package_a.Hello())
	fmt.Println(package_b.Hello())
}
