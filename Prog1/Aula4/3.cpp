#include <iostream>

void dibujarCuadrado(int n, char c)
{
  for (int i = 0; i < n; ++i)
  {
    if (i == 0 || i == n - 1)
    {
      for (int j = 0; j < n; ++j)
      {
        std::cout << c;
      }
    }
    else
    {
      std::cout << c;
      for (int k = 0; k < n - 2; ++k)
      {
        std::cout << " ";
      }
      std::cout << c;
    }
    std::cout << "\n";
  }
}

int main()
{
  int n;
  char c;

  std::cin >> n >> c;
  dibujarCuadrado(n, c);
}