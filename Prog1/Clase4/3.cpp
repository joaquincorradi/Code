#include <iostream>

void dibujarCuadrado(int n, char c)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      std::cout << " " << c << " ";
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