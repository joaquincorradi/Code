#include <iostream>

void cantidadAlumnos(int &cantAlumnos)
{
  std::cout << '\n';
  std::cout << "Ingrese la cantidad del alumnos: ";
  std::cin >> cantAlumnos;
}

void ingresarNotas(int cantAlumnos, int array[])
{
  std::cout << '\n';
  std::cout << "Ingrese las notas:  ";
  for (int i = 0; i <= cantAlumnos - 1; ++i)
  {
    std::cin >> array[i];
  }
}

int deficientes(int array[], int cantAlumnos)
{
  int contador = 0;
  for (int i = 0; i <= cantAlumnos - 1; ++i)
  {
    if (array[i] <= 3)
    {
      ++contador;
    }
  }
  return contador;
}

int regulares(int array[], int cantAlumnos)
{
  int contador = 0;
  for (int i = 0; i <= cantAlumnos - 1; ++i)
  {
    if (array[i] >= 4 && array[i] <= 5)
    {
      ++contador;
    }
  }
  return contador;
}

int buenos(int array[], int cantAlumnos)
{
  int contador = 0;
  for (int i = 0; i <= cantAlumnos - 1; ++i)
  {
    if (array[i] >= 6 && array[i] <= 8)
    {
      ++contador;
    }
  }
  return contador;
}

int excelentes(int array[], int cantAlumnos)
{
  int contador = 0;
  for (int i = 0; i <= cantAlumnos - 1; ++i)
  {
    if (array[i] >= 9 && array[i] <= 10)
    {
      ++contador;
    }
  }
  return contador;
}

void imprimirResultados(int deficientes, int regulares, int buenos, int excelentes)
{
  std::cout << '\n';
  std::cout << "Cantidad de alumnos con notas defiecientes: " << deficientes << '\n';
  std::cout << "Cantidad de alumnos con notas regulares: " << regulares << '\n';
  std::cout << "Cantidad de alumnos con notas buenas: " << buenos << '\n';
  std::cout << "Cantidad de alumnos con notas excelentes: " << excelentes << '\n';
  std::cout << '\n';
}

int main()
{
  int cantAlumnos;
  cantidadAlumnos(cantAlumnos);
  int arrayNotas[cantAlumnos];
  ingresarNotas(cantAlumnos, arrayNotas);
  int def = deficientes(arrayNotas, cantAlumnos);
  int reg = regulares(arrayNotas, cantAlumnos);
  int buen = buenos(arrayNotas, cantAlumnos);
  int exc = excelentes(arrayNotas, cantAlumnos);
  imprimirResultados(def, reg, buen, exc);
}