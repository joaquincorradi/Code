#include <iostream>

void ingresarEdad(int array[14])
{
  std::cout << '\n';
  std::cout << "Ingrese las edades: ";
  for (int i = 0; i <= 13; ++i)
  {
    std::cin >> array[i];
  }
}

int mayores(int array[14])
{
  int contador = 0;
  for (int i = 0; i <= 13; ++i)
  {
    if (array[i] >= 18)
    {
      ++contador;
    }
  }
  return contador;
}

int menores(int array[14])
{
  int contador = 0;
  for (int i = 0; i <= 13; ++i)
  {
    if (array[i] < 18)
    {
      ++contador;
    }
  }
  return contador;
}

int calcPromedio(int array[14])
{
  int promedio = 0;
  for (int i = 0; i <= 13; ++i)
  {
    promedio += array[i];
  }
  return promedio / 14;
}

void mostrarResultados(int mayores, int menores, int promedio)
{
  std::cout << '\n';
  std::cout << "La cantidad de pacientes mayores es " << mayores << " y la cantidad de pacientes menores es " << 
    menores << '\n';
  std::cout << "El promedio de edad es " << promedio << '\n';
  std::cout << '\n';
}

int main()
{
  int edades[14];
  ingresarEdad(edades);
  int may = mayores(edades);
  int men = menores(edades);
  int promedio = calcPromedio(edades);
  mostrarResultados(may, men, promedio);
}