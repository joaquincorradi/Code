package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"net/url"
	"os"
	"strings"
	"time"
)

type Response struct {
	Results []Result
}

type Result struct {
	Title              string  `json:"title"`
	Price              float64 `json:"price"`
	AvailableQuantity  int     `json:"available_quantity"`
	AcceptsMercadopago bool    `json:"accepts_mercadopago"`
	Condition          string  `json:"condition"`
	CategoryID         string  `json:"category_id"`
}

type Category struct {
	Name string `json:"name"`
}

func main() {
	fmt.Println("Ingrese el producto a buscar: ")
	input := readInput()
	results := search(input)

	for i, result := range results {
		category := getCategory(result.CategoryID)
		product := fmt.Sprintf("[%d] %s - $%.2f - %s - %s",
			i+1, result.Title, result.Price, result.Condition, category)
		fmt.Println(product)
		time.Sleep(200 * time.Millisecond)
	}
}

func readInput() string {
	in := bufio.NewReader(os.Stdin)
	input, err := in.ReadString('\n')

	if err != nil {
		fmt.Println(err.Error())
		return ""
	}

	input = strings.TrimSuffix(input, "\n")
	return input
}

func search(query string) []Result {
	// Construyo url
	query = url.QueryEscape(query) // Transforma los caracteres especiales en caracteres válidos para una URL
	urlML := "https://api.mercadolibre.com/sites/MLA/search?q=" + query

	// Hacer request
	resp, err := http.Get(urlML)
	if err != nil {
		fmt.Println(err.Error())
		return nil
	}

	// Valido status code
	// Siempre es mejor validar primero lo negativo para evitar anidaciones (early return)
	if resp.StatusCode != http.StatusOK {
		fmt.Println("Recieve error status code:", resp.StatusCode)
		return nil
	}

	// Leer el body de la respuesta
	bytes, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(err.Error())
		return nil
	}

	// Asignar el body a la estructura Response (parsear)
	var response Response
	err = json.Unmarshal(bytes, &response) //le paso la dirección de memoria de response para que lo modifique
	if err != nil {
		fmt.Println(err.Error())
		return nil
	}

	return response.Results
}

func getCategory(categoryID string) string {
	urlML := "https://api.mercadolibre.com/categories/" + categoryID

	resp, err := http.Get(urlML)
	if err != nil {
		fmt.Println(err.Error())
		return ""
	}

	bytes, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(err.Error())
		return ""
	}

	var category Category
	err = json.Unmarshal(bytes, &category)
	if err != nil {
		fmt.Println(err.Error())
		return ""
	}

	return category.Name
}
