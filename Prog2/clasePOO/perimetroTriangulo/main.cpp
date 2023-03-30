#include "../perimetroTriangulo/triangulo.h"
#include <iostream>

int main() {
  triangulo t(0, 0, 0);
  t.setl1(7);
  t.setl2(5);
  t.setl3(4);
  t.perimetro();
  std::cout << t.getp();
}
