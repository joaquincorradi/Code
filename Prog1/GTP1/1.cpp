#include <iostream>

float sumar(float n1, float n2)
{
  return n1 + n2;
}

int main()
{
  float n1, n2;

  std::cout << "Ingrese los numeros: ";
  std::cin >> n1 >> n2;

  std::cout << sumar(n1, n2) << "\n";
  return 0;
}