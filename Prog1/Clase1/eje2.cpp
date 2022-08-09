#include <iostream>

float promedio (float n1, float n2, float n3, float n4)
{
  return (n1 + n2 + n3 + n4) / 4;
}

int main()
{
  float n1, n2, n3, n4;

  std::cin >> n1 >> n2 >> n3 >> n4;
  std::cout << promedio( n1,  n2,  n3,  n4) << std::endl;
}