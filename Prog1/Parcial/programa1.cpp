#include <iostream>

void ingresarArray(int array[12])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= 11; ++i)
  {
    std::cin >> array[i];
  }
}

void mostrarArray(int array[12])
{
  std::cout << '\n';
  std::cout << "El array ingresado es: [";
  for (int i = 0; i <= 11; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int checkPar(int array[12])
{
  int contador = 0;
  for (int i = 0; i <= 11; ++i)
  {
    if (array[i] % 2 == 0)
    {
      ++contador;
    }
  }
  return contador;
}

int checkImpar(int array[12])
{
  int contador = 0;
  for (int i = 0; i <= 11; ++i)
  {
    if (array[i] % 2 != 0)
    {
      ++contador;
    }
  }
  return contador;
}

void mostrarResultados(int par, int impar)
{
  std::cout << '\n';
  std::cout << "La cantidad de elementos pares es: "  << par <<'\n';
  std::cout << "La cantidad de elementos impares es: "  << impar <<'\n';
  std::cout << '\n';
}

int main()
{
  int array[12];
  ingresarArray(array);
  mostrarArray(array);
  int par = checkPar(array);
  int impar = checkImpar(array);
  mostrarResultados(par, impar);
}