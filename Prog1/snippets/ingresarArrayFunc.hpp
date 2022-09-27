#include <iostream>

void ingresarArray(int n, int array[])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= n - 1; ++i)
  {
    std::cin >> array[i];
  }
}
