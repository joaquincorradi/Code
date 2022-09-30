#include <iostream>

void mostrarArray(int array[3])
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}
