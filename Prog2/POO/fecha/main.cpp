#include "src/fechaCls/fecha.h"
#include <iostream>

int main() {
  fecha *Fecha;
  Fecha = new fecha(1, 1, 1900);

  std::cout << "La fecha es: " << Fecha->getDia() << "/" << Fecha->getMes()
            << "/" << Fecha->getAno() << '\n';
  ++*Fecha;
  std::cout << "La fecha es: " << Fecha->getDia() << "/" << Fecha->getMes()
            << "/" << Fecha->getAno() << '\n';
  *Fecha + 2;

  std::cout << "La fecha es: " << Fecha->getDia() << "/" << Fecha->getMes()
            << "/" << Fecha->getAno() << '\n';

  delete Fecha;
}
