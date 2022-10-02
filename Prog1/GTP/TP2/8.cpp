#include <iostream>

void ingresarNombreAlumno(std::string array[10])
{
  std::cout << '\n';
  std::cout << "Ingrese los nombres de los alumnos: ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cin >> array[i];
  }
}

void ingresarEdadAlumno(int array[10], std::string array2[10])
{
  std::cout << '\n';
  for (int i = 0; i <= 9; ++i)
  {
    std::cout << "Ingrese la edad de " << array2[i] << ": ";
    std::cin >> array[i];
  }
}

void chequearEdad(std::string nombres[10], int edades[10], std::string mayores[10])
{
  int contador = 0;
  for (int i = 0; i <= 9; ++i)
  {
    if (edades[i] > 19)
    {
      mayores[contador] = nombres[i];
      ++contador;
    }
  }
}

void mostrarResultados(std::string array[10])
{
  std::cout << '\n';
  std::cout << "Los alumnos mayores de 19 son: [";
  for (int i = 0; i <= 9; ++i)
  {
    std::cout << " " << array[i] << ", ";
  }
  std::cout << "]";
}

int main()
{
  int edades[10];
  std::string nombres[10], mayores[10];

  ingresarNombreAlumno(nombres);
  ingresarEdadAlumno(edades, nombres);
  chequearEdad(nombres, edades, mayores);
  mostrarResultados(mayores);
}