#include "../superficieTriangulo/triangulo.h"
#include <iostream>

int main() {
  triangulo t(0, 0);
  t.setb(7);
  t.seth(5);
  t.superficie();
  std::cout << t.gets();
}
