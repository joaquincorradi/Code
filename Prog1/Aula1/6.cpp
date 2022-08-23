#include <cmath>
#include <iostream>

float calcularArea(float a, float b, float c, float s)
{
  float area = sqrt(s * (s - a) * (s - b) * (s - c)); 
  return area;
}

int main()
{
  float a, b, c, s;

  std::cin >> a >> b >> c >> s;
  std::cout << calcularArea(a, b, c, s) << std::endl;
}