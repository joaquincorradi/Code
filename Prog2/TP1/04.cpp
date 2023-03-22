#include <iostream>

int calcularFactorial(int n);

int main() {
  int n = 5, factorial = calcularFactorial(n);
  std::cout << factorial << '\n';
}

int calcularFactorial(int n) {
  int i = 1, factorial;
  while (i <= n) {
    factorial *= i;
    ++i;
  }
  return factorial;
}
