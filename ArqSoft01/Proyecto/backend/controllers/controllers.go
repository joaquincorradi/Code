package controllers

import (
	"net/http"

	"backend/models"

	"github.com/gin-gonic/gin"
)

func Ping(c *gin.Context) {
	c.JSON(http.StatusOK, models.Response{Message: "pong"})
}
