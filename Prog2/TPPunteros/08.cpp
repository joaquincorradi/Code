#include <iostream>

int main() {
  int x = 5, y = 10, z = 15;
  int *p;
  p = &x;
  std::cout << *p << '\n';
  p = &y;
  std::cout << *p << '\n';
  p = &z;
  std::cout << *p << '\n';
}
