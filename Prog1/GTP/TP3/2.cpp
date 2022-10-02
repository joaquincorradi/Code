#include <iostream>

void ingresarNombre(std::string nombres[6])
{
  std::cout << '\n';
  std::cout << "Ingrese los nombres: ";
  for (int i = 0; i <= 5; ++i)
  {
    std::cin >> nombres[i];
  }
}

void ingresarEdad(int edades[6], std::string nombres[6])
{
  std::cout << '\n';
  for (int i = 0; i <= 5; ++i)
  {
    std::cout << "Ingrese la edad de " << nombres[i] << ": ";
    std::cin >> edades[i];
  }
}

int cantidadEdad(int edades[6])
{
  int contador = 0;
  for (int i = 0; i <= 5; ++i)
  {
    if (edades[i] == 18 || edades[i] == 20 || edades[i] == 22)
    {
      ++contador;
    }
  }
  return contador;
}

void guardadNombres(int edades[6], std::string nombres[6], std::string edadEspecifica[])
{
  int contador = 0;
  for (int i = 0; i <= 5; ++i)
  {
    if (edades[i] == 18 || edades[i] == 20 || edades[i] == 22)
    {
      edadEspecifica[contador] = nombres[i];
      ++contador;
    }
  }
}

void mostrarArray(int cant, std::string array[])
{
  std::cout << '\n';
  std::cout << "El array es: [";
  for (int i = 0; i <= cant - 1; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int main()
{
  std::string nombres[6];
  ingresarNombre(nombres);
  int edades[6];
  ingresarEdad(edades, nombres);
  int cant = cantidadEdad(edades);
  std::string edadEspecifica[cant];
  guardadNombres(edades, nombres, edadEspecifica);
  mostrarArray(cant, edadEspecifica);
}