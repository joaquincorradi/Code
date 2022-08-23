#include <iostream>

void decenasUnidades(int n)
{
  int decenas = n / 10;
  int unidades = n;

  std::cout << "El numero " << n << " tiene " << decenas << " decenas y " << 
    unidades << " unidades." << std::endl;
}

int main()
{
  int n;

  std::cin >>  n;
  decenasUnidades(n);
}