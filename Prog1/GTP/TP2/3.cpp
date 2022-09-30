#include <iostream>

void tamanoArray(int &tamano)
{
  std::cout << '\n';
  std::cout << "Ingrese tamano array: ";
  std::cin >> tamano;
}

void ingresarArray(int tamano, int array[])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= tamano - 1; ++i)
  {
    std::cin >> array[i];
  }
}

void sumarArrays(int n, int array1[], int array2[], int arraySuma[])
{
  for (int i = 0; i <= n - 1; ++i)
  {
    arraySuma[i] = array1[i] + array2[i];
  }
}

void mostrarArray(int array[], int tamano)
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= tamano - 1; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int main()
{
  int tamano;
  tamanoArray(tamano);
  int array1[tamano], array2[tamano], arraySuma[tamano];
  ingresarArray(tamano, array1);
  ingresarArray(tamano, array2);
  sumarArrays(tamano, array1, array2, arraySuma);
  mostrarArray(arraySuma, tamano);
}