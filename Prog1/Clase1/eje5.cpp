#include <iostream>

float sueldo(float h, float v)
{
  return h * v;
}

int main()
{
  float h, v;

  std::cin >> h >> v;
  std::cout << sueldo(h, v);
}