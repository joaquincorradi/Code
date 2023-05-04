#include "../alumno/alumno.h"
#include <iostream>
#include <string>

alumno::alumno(int x, std::string y, std::string z, std::string w,
               std::string u, int v, float j)
    : persona(x, y, z, w) {
  carrera = u;
  edad = v;
  nota = j;
}

void alumno::setNota(int x) { nota = x; }
float alumno::getNota() { return nota; }

void alumno::modificarDatosAlumno() {
  modificarDatos();
  std::cout << "Ingrese su carrera: ";
  std::cin >> carrera;
  std::cout << "Ingrese su edad: ";
  std::cin >> edad;
}
