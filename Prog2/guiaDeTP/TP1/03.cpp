#include <iostream>

int calcMCD(int a, int b);

int main() {
  int a = 4, b = 10, mcd = calcMCD(a, b);
  std::cout << mcd << '\n';
}

int calcMCD(int a, int b) {
  while (a != b) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return a;
}
