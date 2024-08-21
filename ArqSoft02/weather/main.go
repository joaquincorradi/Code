package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"weather/dto"
)

func main() {
	args := os.Args
	userIdParam := args[1]

	resp, err := http.Get(fmt.Sprintf("https://api.mercadolibre.com/users/%s", userIdParam))
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	defer resp.Body.Close()

	respondeData, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	var userDto dto.User
	json.Unmarshal(respondeData, &userDto)

	fmt.Println("Usuario:", userDto.Nickname)

	// ---

	resp2, err := http.Get(fmt.Sprintf("https://api.mercadolibre.com/countries/%s", userDto.Country))
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	defer resp2.Body.Close()

	respondeData2, err := io.ReadAll(resp2.Body)
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	var countryDto dto.Country
	json.Unmarshal(respondeData2, &countryDto)

	fmt.Println("País:", countryDto.Name)
	fmt.Println("Latitud:" + fmt.Sprintf("%f", countryDto.Geoinformation.Location.Latitude))
	fmt.Println("Longitud:" + fmt.Sprintf("%f", countryDto.Geoinformation.Location.Longitude))

	// ---

	resp3, err := http.Get(fmt.Sprintf("https://api.open-meteo.com/v1/forecast?latitude=%f&longitude=%f&daily=precipitation_hours,precipitation_sum", countryDto.Geoinformation.Location.Latitude, countryDto.Geoinformation.Location.Longitude))
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	defer resp3.Body.Close()

	respondeData3, err := io.ReadAll(resp3.Body)
	if err != nil {
		fmt.Println("Error:", err)
		log.Fatal(err)
	}

	var weatherDto dto.Weather
	json.Unmarshal(respondeData3, &weatherDto)

	for i := 0; i < 7; i++ {
		fmt.Println("\nDía:", weatherDto.Daily.Time[i])
		fmt.Println("Horas:", weatherDto.Daily.PrecipitationHours[i])
		fmt.Println("Milímetros:", weatherDto.Daily.PrecipitationSum[i])
	}
}
