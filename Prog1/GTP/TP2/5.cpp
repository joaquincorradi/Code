#include <endian.h>
#include <iostream>

void arrayConPares(long array[20])
{
  int contador = 0;
  for (long i = 1; i <= 41; ++i)
  {
    if (i % 2 == 0)
    {
      array[contador] = i;
      ++contador;
    }
  }
}

int sumarArray(long array[20])
{
  int suma = 0;
  for (int i = 0; i <= 19; ++i)
  {
    suma += array[i];
  }
  return suma;
}

void mostrarArray(long array[20])
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= 19; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
  std::cout << '\n';
}

void mostrarResultado(int suma)
{
  std::cout << '\n';
  std::cout << "La suma de los primeros numeros pares es: " << suma << '\n';
}

int main()
{
  long array[20];
  arrayConPares(array);
  mostrarArray(array);
  int suma = sumarArray(array);
  mostrarResultado(suma);
}