#include <iostream>

int main() {
  int *p, z;
  p = &z;
  *p = 4;
  std::cout << z;
}
