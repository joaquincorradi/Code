#include <iostream>

void tipoTriangulo(float a, float b, float c)
{
  if (a == b && b == c)
  {
    std::cout << "Equilatero." << "\n";
  }
  else if (a == b || b == c || a == c)
  {
    std::cout << "Isosceles." << "\n";
  }
  else 
  {
    std::cout << "Escaleno." << "\n";
  }
}

int main()
{
  float a, b, c;

  std::cin >> a >> b >> c;
  tipoTriangulo(a, b, c);
}