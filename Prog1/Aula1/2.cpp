#include <iostream>

float promedioSimple(int n1, int n2, int n3, int n4)
{
  return (n1 + n2 + n3 + n4) / 4.;
}

int main()
{
  int n1, n2, n3, n4;

  std::cin >> n1 >> n2 >> n3 >> n4;
  std::cout << promedioSimple(n1, n2, n3, n4);
}