#include <iostream>

void ingresarNumeros(int &n1, int &n2)
{
  std::cout << "Ingrese dos numeros: ";
  std::cin >> n1 >> n2;
}

int suma(int n1, int n2)
{
  return n1 + n2;
}

int main()
{
  int n1, n2;
  ingresarNumeros(n1, n2);
  int sumaNum = suma(n1, n2);
  std::cout << "La suma es: " << suma(n1, n2) << std::endl;
}
