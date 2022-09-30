#include <iostream>

void tamanoArray(int &tamano)
{
  std::cout << '\n';
  std::cout << "Ingrese tamano array: ";
  std::cin >> tamano;
}

void ingresarNumero(int &numero)
{
  std::cout << '\n';
  std::cout << "Ingrese un numero entero: ";
  std::cin >> numero;
}

void mostrarMultiplos(int array[], int tamano, int numero)
{
  for (int i = 0; i <= tamano - 1; ++i)
  {
    array[i] = numero * (i + 1);
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
  int array[tamano];
  int numero;
  ingresarNumero(numero);
  mostrarMultiplos(array, tamano, numero);
  mostrarArray(array, tamano);
}