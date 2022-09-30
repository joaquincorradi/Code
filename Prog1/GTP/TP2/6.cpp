#include <iostream>

void ingresarArray(int array[5])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= 4; ++i)
  {
    std::cin >> array[i];
  }
}

void mostrarArray(int array[5])
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= 4; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int calcularPromedio(int array[5])
{
  int promedio = 0;
  for (int i = 0; i <= 4; ++i)
  {
    promedio += array[i];
  }
  promedio /= 5;
  return promedio;
}

void mostrarResultado(int promedio)
{
  std::cout << '\n';
  std::cout << "El promedio de los numeros ingresados es: " << promedio << '\n';
  std::cout << '\n';
}

int main()
{
  int array[5];
  ingresarArray(array);
  mostrarArray(array);
  int promedio = calcularPromedio(array);
  mostrarResultado(promedio);
}