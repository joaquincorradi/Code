#include <iostream>

int main() {
  int *px, x = 4;
  float *py, y = 5;
  px = &x;
  py = &y;
  std::cout << *px << *py;
}
