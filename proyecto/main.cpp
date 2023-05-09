#include "src/clase2/clase2.h"
#include <iostream>

int main() {
  clase2 *Clase;
  Clase = new clase2(0, 0.0, 0, 'A');

  int x;
  int *pX = &x;

  float y;
  float *pY = &y;

  std::cout << "Ingrese dos numeros: ";
  std::cin >> *pX >> *pY;

  Clase->setN(*pX);
  Clase->setM(*pY);

  Clase->sumarNumeros();
  std::cout << "El valor de mi caracter es: " << Clase->getY() << '\n';

  delete Clase;
}
