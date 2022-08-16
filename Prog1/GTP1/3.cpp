#include <iostream>

float cualMayor(float n1, float n2)
{
  float n;
  
  if (n1 < n2)
  {
    n = n2;
  }
  else if (n1 > n2)
  {
    n = n1;
  }
  else if (n1 == n2)
  {
    n = 0;
  }

  return n;
}

int main()
{
  float n1, n2;

  std::cout << "Ingrese los numeros: ";
  std::cin >> n1, n2;

  std::cout << cualMayor(n1, n2) << std::endl;

  return 0;
}