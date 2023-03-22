#include <iostream>

void ingresarDatos(int &n, int polinomio[], int &x);
int evaluarPolinomio(int n, int polinomio[], int x);

int main() {
  int n, x;
  int polinomio[n];
  ingresarDatos(n, polinomio, x);
  int evaluar = evaluarPolinomio(n, polinomio, x);
  std::cout << "El polinomio evaluado es: " << evaluar << '\n';
}

void ingresarDatos(int &n, int polinomio[], int &x) {
  std::cout << "Ingrese grado del polinomio: ";
  std::cin >> n;
  std::cout << "Ingrese valor de X: ";
  std::cin >> x;
  for (int i = 0; i < n; ++i) {
    std::cout << "Ingrese coeficiente x^" << i << ": ";
    std::cin >> polinomio[i];
  }
}

int evaluarPolinomio(int n, int polinomio[], int x) {
  int suma = polinomio[0];
  for (int i = 1; i < n; ++i) {
    suma += (polinomio[i] * x);
  }
  return suma;
}
