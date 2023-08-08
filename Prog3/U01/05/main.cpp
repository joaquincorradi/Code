#include <iostream>

int cociente(int, int);
int resto(int, int);
void imprimirNumero(int);

int main() {
  std::cout << cociente(10, 3) << '\n';
  std::cout << resto(10, 3) << '\n';
  imprimirNumero(103);
}

int cociente(int a, int b) {
  // si a es mayor que b y se divide da 0,... entonces la parte entera es 0
  if (a < b) {
    return 0;
  } else {
    // restamos para saber cuantas veces entra b en a
    return cociente(a - b, b) + 1;
  }
}

int resto(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return resto(a - b, b);
  }
}

void imprimirNumero(int n) {
  if (resto(n, 10) == n) {
    std::cout << " " << resto(n, 10);
  }

  imprimirNumero(cociente(n, 10));
  std::cout << " " << resto(n, 10);
}
