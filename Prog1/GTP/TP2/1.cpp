#include <iostream>

void ingresarArray(int array[5])
{
  std::cout << '\n';
  std::cout << "Ingrese el array";
  for (int i = 0; i <= 2; ++i)
  {
    std::cin >> array[i];
  }
}

void mostrarArray()
