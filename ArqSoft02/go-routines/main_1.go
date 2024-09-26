package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	go processUsers()
	time.Sleep(3 * time.Second)
}

func processUsers() {
	var i int64 = 0
	for true {
		go processUser(i)
		time.Sleep(time.Duration(200+rand.Intn(300)) * time.Millisecond)
		i++
	}
}

func processUser(userID int64) string {
	result := fmt.Sprintf("Processing user: %d", userID)
	time.Sleep(1 * time.Second)
	return result
}
