package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func readFile(path string) ([]byte, error) {
	// Abrir el archivo
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}

	// Defer se ejecuta al final de la función y cierra el archivo
	defer func() {
		err := file.Close()
		if err != nil {
			fmt.Println("Error al cerrar el archivo: ", err.Error())
		}
	}()

	// Leer el archivo. Guardamos el contenido en un slice de bytes "b"
	b, err := ioutil.ReadAll(file)
	if err != nil {
		return nil, err
	}

	return b, nil
}

func main() {
	b, err := readFile("./clase.txt")

	if err != nil {
		fmt.Println("Error: ", err.Error())
		return
	}

	// Con string(b) convertimos el slice de bytes en un string
	fmt.Println("Archivo leído: ", string(b))
}
