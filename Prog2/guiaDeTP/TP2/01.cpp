#include <iostream>

int main() {
  int x = 2, y = 3, *p;

  p = &x;
  std::cout << "Direccion de memoria apuntada: " << p << '\n';
  std::cout << "Contenido: " << *p << '\n';

  p = &y;
  std::cout << "Direccion de memoria apuntada: " << p << '\n';
  std::cout << "Contenido: " << *p << '\n';
}
