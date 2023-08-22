#include <iostream>

int sumar(int[], int);

int main() {
  int arr[3] = {1, 2, 3};
  int suma = sumar(arr, 3);
  std::cout << suma << '\n';
}

int sumar(int arr[], int tam) {
  if (tam == 0) {
    return 0; // Caso base: suma de ningún elemento es 0
  } else {
    return sumar(arr, tam - 1) + arr[tam - 1];
  }
}
