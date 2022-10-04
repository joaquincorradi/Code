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

void chequearCantidad(int array[12], int &cero, int &uno, int &dos)
{
  for (int i = 0; i <= 11; ++i)
  {
    if (array[i] == 0)
    {
      ++cero;
    }
    else if (array[i] == 1)
    {
      ++uno;
    }
    else
    {
      ++dos;
    }
  }
}

void mostrarResultados(int cero, int uno, int dos)
{
  std::cout << '\n';
  std::cout << "La cantidad de numeros 0 es: " << cero << '\n';
  std::cout << "La cantidad de numeros 1 es: " << uno << '\n';
  std::cout << "La cantidad de numeros 2 es: " << dos << '\n';
  std::cout << '\n';
}

int main()
{
  int array [12];
  ingresarArray(array);
  int cero = 0, uno = 0, dos = 0;
  chequearCantidad(array, cero, uno, dos);
  mostrarResultados(cero, uno, dos);
}