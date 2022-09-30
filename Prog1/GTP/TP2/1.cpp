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

void mostarArray(int array[5])
{
  std::cout << '\n';
  std::cout << "El array es: ";
  for (int i = 0; i <= 4; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int main()
{
  int array[5];
  ingresarArray(array);
  mostarArray(array);
}