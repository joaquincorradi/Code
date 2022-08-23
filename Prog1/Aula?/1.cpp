#include <iostream>

float calcCubo (float n, float e)
{
  int  i = 1;
  float p = n;
  while (i < e)
  {
    p *= n;
    ++i;
  }

  return p;
}

int main()
{
  float n, e;

  std::cin >> n >> e;
  std::cout << calcCubo(n, e) << std::endl;
}