#include <iostream>

int funcion1(int x);
void funcion2(int *p);

int main() {
  int x = 4, f1 = funcion1(x);
  std::cout << f1;
  int *p = &x;
  funcion2(p);
  std::cout << x;
}

int funcion1(int x) { return x * 2; }

void funcion2(int *p) { *p *= 3; }
