package main

import (
	"backend/controllers"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	router.GET("/ping", controllers.Ping)

	router.Run()
}
