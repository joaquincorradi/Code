package main

import (
	"log"
	"net/http"
)

const DefaultPort = "8089"

// EchoHandler devuelve el request que recibe del cliente
func EchoHandler(writer http.ResponseWriter, request *http.Request) {
	// Imprime en terminal el request recibido
	log.Println("Echoing back request made to: " + request.URL.Path + " to client (" + request.RemoteAddr + ")")

	// Seteamos los headers de la respuesta
	writer.Header().Set("Access-Control-Allow-Origin", "*")

	// Seteamos los métodos permitidos
	writer.Header().Set("Access-Control-Allow-Methods", "Content-Range, Content-Disposition, Content-Type, ETag")

	// Seteamos el tipo de contenido
	request.Write(writer)
}

func main() {
	log.Println("Starting server. Listening on port " + DefaultPort)

	http.HandleFunc("/", EchoHandler)
	http.ListenAndServe(":"+DefaultPort, nil)
}
