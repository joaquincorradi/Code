#include <iostream>

int calcCantDivisores(int a, int b, int k);

int main() {
  int a, b, k;
  std::cin >> a >> b >> k;
  int divisores = calcCantDivisores(a, b, k);
  std::cout << divisores << '\n';
}

int calcCantDivisores(int a, int b, int k) {
  int divisores = 0;
  for (int i = a; i < b; ++i) {
    if (k % i == 0) {
      ++divisores;
    }
  }
  return divisores;
}
