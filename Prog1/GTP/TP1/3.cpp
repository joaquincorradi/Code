#include <iostream>

void ingresarNumeros(int &n1, int &n2)
{
  std::cout << "Ingrese dos numeros: ";
  std::cin >> n1 >> n2;
}

int devolverMayor(int n1, int n2)
{
  if (n1 < n2)
  {
    return n2;
  }
  else
  {
    return n1;
  }
}

int main()
{
  int n1, n2;
  ingresarNumeros(n1, n2);
  std::cout << "El mayor es: " << devolverMayor(n1, n2) << '\n';
} 
