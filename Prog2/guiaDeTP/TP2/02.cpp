#include <iostream>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int *p = array;

  for (int i = 0; i < 5; ++i) {
    std::cout << "La direccion de memoria del espacio " << i << " es " << p[i]
              << '\n';
  }
}
