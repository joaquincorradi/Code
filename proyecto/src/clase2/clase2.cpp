#include "./clase2.h"
#include <iostream>

// clase2::clase2(int _n, float _m, int _x, char _y) : clase1(_n, _m) {
//   x = _x;
//   y = _y;
// }

clase2::clase2(int _n, float _m, int _x, int _y)
    : clase1(_n, _m), x{_x}, y{_y} {}

int clase2::getX() { return x; }
char clase2::getY() { return y; }

void clase2::setX(int _x) { x = _x; }
void clase2::setY(char _y) { y = _y; }

int clase2::sumarNumeros2(int a) { return x + a; }
void clase2::agregarNumeros() {
  sumarNumeros();
  std::cout << "Mi numero es " << x << ", y mi caracter es " << y << '\n';
}
