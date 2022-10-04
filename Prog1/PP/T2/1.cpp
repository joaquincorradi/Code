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

int calcMasVeces(int array[12])
{
  int cero = 0; int uno = 0, resultado;
  for (int i = 0; i <= 11; ++i)
  {
    if (array[i] == 0)
    {
      ++cero;
    }
    else
    {
      ++uno;
    }
  }
  if (cero > uno)
  {
    resultado = 0;
  }
  else if (cero < uno)
  {
    resultado = 1;
  }
  else
  {
    resultado = 10;
  }
  return resultado;
}

void mostrarResultados(int mas)
{
  std::cout << '\n';
  std::cout << "El resultado que aprece mas veces es: " << mas <<'\n';
  std::cout << '\n';
}

int main()
{
  int array[12];
  ingresarArray(array);
  int mas = calcMasVeces(array);
  mostrarResultados(mas);
}