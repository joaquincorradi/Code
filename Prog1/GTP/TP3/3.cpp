#include <iostream>

void ingresarNombre(std::string nombres[10])
{
  std::cout << '\n';
  std::cout << "Ingrese los nombres: ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cin >> nombres[i];
  }
}

void ingresarEdad(int edades[10], std::string nombres[10])
{
  std::cout << '\n';
  for (int i = 0; i <= 9; ++i)
  {
    std::cout << "Ingrese la edad de " << nombres[i] << ": ";
    std::cin >> edades[i];
  }
}

int chequearMaria(std::string nombres[10], int edades[10])
{
  int guardar;
  for (int i = 0; i <= 9; ++i)
  {
    if (nombres[i] == "maria" || nombres[i] == "Maria")
    {
      guardar = edades[i];
    }
  }
  return guardar;
}

void mostrarResultados(int maria)
{
  std::cout << '\n';
  std::cout << "La edad de Maria es: " << maria << '\n';
}

int main()
{
  std::string nombres[10];
  ingresarNombre(nombres);
  int edades[10];
  ingresarEdad(edades, nombres);
  int maria = chequearMaria(nombres, edades);
  mostrarResultados(maria);
}