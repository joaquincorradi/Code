#include <iostream>

int puntaje(int g, int p, int e)
{
  return (3 * g) + e;
}

int main()
{
  int g, p, e;

  std::cin >> g >> p >> e;
  std::cout << puntaje(g, p, e);
}