package main

import (
	"fmt"
	"strings"
)

func main() {
	var conferenceName = "Go Conference"
	const totalTickets = 50
	var remainingTickets uint = 50
	var bookings = []string{}

	fmt.Printf("Welcome to %v booking app\n", conferenceName)
	fmt.Println()

	fmt.Printf("Total tickets: %v\n", totalTickets)
	fmt.Printf("Remaining tickets: %v\n", remainingTickets)
	fmt.Println()

	for {
		var firstName string
		var lastName string
		var email string
		var userTickets int

		fmt.Print("Enter your first name: ")
		fmt.Scan(&firstName)

		fmt.Print("Enter your last name: ")
		fmt.Scan(&lastName)

		fmt.Print("Enter your email: ")
		fmt.Scan(&email)

		fmt.Print("How many ticket do you want? ")
		fmt.Scan(&userTickets)

		remainingTickets -= uint(userTickets)
		bookings = append(bookings, firstName+" "+lastName+", ")

		fmt.Printf("Thank you %v %v for booking %v tickets. You'll recieve a confimation email at %v\n",
			firstName, lastName, userTickets, email)

		fmt.Println()
		fmt.Printf("%v tickets remaining for %v\n", remainingTickets, conferenceName)

		var firstNames = []string{}

		for _, booking := range bookings {
			var names = strings.Fields(booking)
			var firtName = names[0]
		}

		fmt.Printf("These are all our bookings: %v", bookings)
		fmt.Println()

	}
}
