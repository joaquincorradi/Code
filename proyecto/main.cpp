#include "src/clase2/clase2.h"
#include "src/clase3/clase3.h"
#include <iostream>

int main() {
  clase2 *Clase;
  Clase = new clase2(0, 0.0, 0, 'A');

  clase3 *Clase3;
  Clase3 = new clase3(0);

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

  Clase3->Clase1->imprimirClase1();
  Clase->imprimirClase1();

  delete Clase;
  delete Clase3;
}
