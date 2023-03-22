#include <iostream>

void ingresarDatos(int &n, int array[]);

int main() {
  int n, array[n];
  void ingresarDatos(n, array);
}

void ingresarDatos(int &n, int array[]) {
  std::cout << "Ingrese el tamano del arreglo: ";
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cout << "Ingrese elemento " << i << ": ";
    std::cin >> array[i];
  }
}
