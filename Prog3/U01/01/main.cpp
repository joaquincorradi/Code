#include <iostream>

int potencia(int, int);

int main() {
  std::cout << potencia(3, 2);
  return 0;
}

int potencia(int base, int exponente) {
  // Condicion base
  if (exponente == 0) {
    return 1;
  }

  // Recursion
  return potencia(base, exponente - 1) * base;
}
