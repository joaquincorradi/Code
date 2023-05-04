#ifndef _ESTRUCTURAH_
#define _ESTRUCTURAH_

#include "../estructura/estructura.h"
#include <iostream>

estructura::estructura() {}

void estructura::menu() {
  int x;
  std::cout << "MENU PRINCIPAL\n";
  std::cout << "[1] Darse de alta.\n";
  std::cout << "[2] Incribirse a materia.\n";
  std::cout << "[3] Anotar titular de materia.\n";
  std::cout << "[4] Cargar notas.\n";
  std::cout << "[5] Modificar datos.\n";
  std::cout << "[6] Salir.";
  std::cout << "Elija una opcion:";
  std::cin >> x;
}

void estructura::setOpcion(int x) { opcion = x; }
int estructura::getOpcion() { return opcion; }

#endif // !_ESTRUCTURAH_
