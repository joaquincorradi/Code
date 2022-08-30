#include <iostream>

float cuadradoCubo(float n, float &cuadrado, float &cubo)
{
  cuadrado = n * n;
  cubo = n * n * n;

  return n;
}

int main()
{
  float n, cuadrado, cubo;
  std::cin >> n;

  float func = cuadradoCubo(n, cuadrado, cubo);

  std::cout << "El cuadrado de " << n << " es " << cuadrado << "\n";
  std::cout << "El cubo de " << n << " es " << cubo << "\n";
}