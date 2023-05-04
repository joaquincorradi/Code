#include "../docente/docente.h"
#include "../materia/materia.h"
#include <iostream>
#include <string>

docente::docente(int x, std::string y, std::string z, std::string w,
                 std::string u)
    : persona(x, y, z, w) {
  titulo = u;
}

void docente::asignarMateria(std::string x) { Materia.setTitular(x); }

void docente::modificarDatosDocente() {
  modificarDatos();
  std::cout << "Ingrese su titulo: ";
  std::cin >> titulo;
}
