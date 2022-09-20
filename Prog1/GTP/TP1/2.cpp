#include <iostream>

void ingresarNumeros(int &n)
{
  std::cout << "Ingrese un numero: ";
  std::cin >> n;
}

char negativoPositivo(int n)
{
  if (n < 0)
  {
    return 'N';
  }
  else if (n > 0)
  {
    return 'P';
  }
  else
  {
    return 'C';
  }
}

int main()
{
  int n;
  ingresarNumeros(n);
  std::cout << negativoPositivo(n);
}
