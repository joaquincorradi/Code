#include <iostream>

void queSigno(int n)
{
  if (n == 0)
  {
    std::cout << "C" << "\n";
  }
  else if (n > 0)
  {
    std::cout << "P" << "\n";
  }
  else if (n < 0)
  {
    std::cout << "N" << "\n";
  }
}

int main()
{
  int n;

  std::cout << "Ingrese un numero: ";
  std::cin >> n;

  queSigno(n);
}