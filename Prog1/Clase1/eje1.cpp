#include <iostream>

float mru(float v, float t)
{
  return v * t;
}

int main()
{
  float d, v, t;

  std::cin >> v;
  std::cin >> t;

  std::cout << mru(v, t);
}