#include <iostream>

void tamanoArray(int &tamano)
{
  std::cout << '\n';
  std::cout << "Ingrese tamano del array: ";
  std::cin >> tamano;
}

void ingresarArray(int n, int array[])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= n - 1; ++i)
  {
    std::cin >> array[i];
  }
}

void invertirArray(int n, int array1[], int array2[])
{
  for (int i = 0; i <= n - 1; ++i)
  {
    array2[i] = array1[(n - 1) - i];
  }
}

void mostrarArray(int n, int array[])
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= n - 1; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int main()
{
  int tamano;
  tamanoArray(tamano);
  int array1[tamano], array2[tamano];
  ingresarArray(tamano, array1);
  invertirArray(tamano, array1, array2);
  mostrarArray(tamano, array1);
  mostrarArray(tamano, array2);
}