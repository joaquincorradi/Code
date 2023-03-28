#include <iostream>

int main() {
  float x, y;
  float *p;
  p = &x;
  *p = 4;
  p = &y;
  *p = 5;
  std::cout << x << y;
}
