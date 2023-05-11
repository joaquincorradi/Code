#include "./libro.h"
#include <iostream>
#include <string>

libro::libro(std::string _nombreDelLibro, std::string _autorDelLibro,
             int _anoDePublicacion, bool _disponibilidadDelLibro) {
  nombreDelLibro = _nombreDelLibro;
  autorDelLibro = _autorDelLibro;
  anoDePublicacion = _anoDePublicacion;
  disponibilidadDelLibro = _disponibilidadDelLibro;
}

std::string libro::getNombreDelLibro() { return nombreDelLibro; }
std::string libro::getAutorDelLibro() { return autorDelLibro; }
int libro::getAnoDePublicacion() { return anoDePublicacion; }
bool libro::getDisponibilidadDelLibro() { return disponibilidadDelLibro; }

void libro::setNombreDelLibro(std::string _nombreDelLibro) {
  nombreDelLibro = _nombreDelLibro;
}
void libro::setAutorDelLibro(std::string _autorDelLibro) {
  autorDelLibro = _autorDelLibro;
}
void libro::setAnoDePublicacion(int _anoDePublicacion) {
  anoDePublicacion = _anoDePublicacion;
}
void libro::setDisponibilidadDelLibro(bool _disponibilidadDelLibro) {
  disponibilidadDelLibro = _disponibilidadDelLibro;
}

void libro::iniciarPrestamo(bool valor) {
  if (nombreDelLibro != "") {
    disponibilidadDelLibro = false;
    valor = true;
  } else {
    std::cout << "Primero debe ingresar un libro.\n";
  }
}
