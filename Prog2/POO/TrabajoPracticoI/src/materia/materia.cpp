#include "./materia.h"
#include <iostream>

materia::materia() {}
materia::materia(int x, std::string y, int z, int w) {
  codigo = x;
  nombre = y;
  nota = z;
  titular = w;
}

void materia::setCodigo(int x) { codigo = x; }
void materia::setNombre(std::string x) { nombre = x; }
void materia::setNota(int x) { nota = x; }

int materia::getCodigo() { return codigo; }
std::string materia::getNombre() { return nombre; }
int materia::getNota() { return nota; }
