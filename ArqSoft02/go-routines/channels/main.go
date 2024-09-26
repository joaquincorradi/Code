package channels

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
	i := 0
	ch := make(chan string)
	go func() {
		for true {
			r := <-ch
			fmt.Println(r)
		}
	}()
	for true {
		go processUser(i, ch)
		time.Sleep(time.Duration(200+rand.Intn(300)) * time.Millisecond)
		i++
	}
}

func processUser(userID int, ch chan string) {
	result := fmt.Sprintf("Processing user: %d", userID)
	time.Sleep(1 * time.Second)
	ch <- result
}
