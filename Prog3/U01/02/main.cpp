#include <iostream>

int sumar(int[], int);

int main() {}

int sumar(int arr[], int tam) {
  if (tam == 0) {
    return arr[0];
  } else {
    return sumar(arr, tam - 1) + arr[tam - 1];
  }
}
