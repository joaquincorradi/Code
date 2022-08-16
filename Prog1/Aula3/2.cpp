#include <iostream>

float div(float n1, float n2)
{
  return n1 / n2;
}

int main()
{
  float n1, n2;

  std::cin >> n1 >> n2;
  std::cout << div(n1, n2) << std::endl;
}