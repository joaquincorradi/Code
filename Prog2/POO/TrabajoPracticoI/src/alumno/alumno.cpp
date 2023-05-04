#include "../alumno/alumno.h"
#include <iostream>
#include <string>

alumno::alumno(int x, std::string y, std::string z, std::string w,
               std::string u, int v)
    : persona(x, y, z, w) {
  carrera = u;
  edad = v;
}

void alumno::inscripcionEnMateria() {}
