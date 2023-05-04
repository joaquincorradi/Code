#include "../alumno/alumno.h"
#include <iostream>
#include <string>

void alumno::inscripcionEnMateria() {
  int x;
  std::string y;
  std::cout << "Ingrese el codigo de la materia: ";
  std::cin >> x;
  Materia.setCodigo(x);

  std::cout << "Ingrese el nombre de la materia:";
  std::cin >> x;
  Materia.setNombre(y);
}
