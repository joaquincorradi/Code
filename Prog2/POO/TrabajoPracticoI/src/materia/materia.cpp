#include "./materia.h"
#include <iostream>

materia::materia() {}
materia::materia(int x, std::string y, std::string z) {
  codigo = x;
  nombre = y;
  titular = z;
}

void materia::setCodigo(int x) { codigo = x; }
void materia::setNombre(std::string x) { nombre = x; }
void materia::setTitular(std::string x) { titular = x; }

int materia::getCodigo() { return codigo; }
std::string materia::getNombre() { return nombre; }
std::string materia::getTitular() { return titular; }

void materia::inscripcionEnMateria(int x, std::string y) {
  codigo = x;
  nombre = y;
}
