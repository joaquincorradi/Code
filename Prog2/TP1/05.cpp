#include <iostream>

void ingresarDatos(int &n, int &m);
bool mismoConjunto(int n, int m);

int main() {
  int n, m;
  ingresarDatos(n, m);
  bool chequear = mismoConjunto(n, m);
}

void ingresarDatos(int &n, int &m) {
  std::cout << "Ingrese un entero N: ";
  std::cin >> n;
  std::cout << "Ingrese un entero M: ";
  std::cin >> m;
}
