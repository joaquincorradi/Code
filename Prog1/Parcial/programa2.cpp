#include <iostream>

void ingresarMatriz(float matriz[3][3])
{
  std::cout << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << "Ingrese la fila " << i + 1 << ": ";
    for (int j = 0; j <= 2; ++j)
    {
      std::cin >> matriz[i][j];
    }
  }
}

float calcPromedio(float matriz[3][3])
{
  float promedio = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      promedio += matriz[i][j];
    }
  }
  return promedio / 9;
}

void dividirMatrizPromedio(float matriz[3][3], float promedio)
{
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      matriz[i][j] = matriz[i][j] / promedio;
    }
  }
}

void matrizAArray(float matriz[3][3], float array[9])
{
  int contador = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      array[contador] = matriz[i][j];
      ++contador;
    }
  }
}

void mostrarPromedio(float promedio)
{
  std::cout << '\n';
  std::cout << "El promedio es " << promedio  <<'\n';
  std::cout << '\n';
}

void mostrarMatriz(float matriz[3][3])
{
  std::cout << '\n';
  std::cout << "La matriz resultante es: " << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      std::cout << " " << matriz[i][j] << " ";
    }
    std::cout << '\n';
  }
}

void mostrarArray(float array[9])
{
  std::cout << '\n';
  std::cout << "El array resultante es: [";
  for (int i = 0; i <= 8; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
  std::cout << '\n';
}

int main()
{
  float matriz[3][3];
  ingresarMatriz(matriz);
  float promedio = calcPromedio(matriz);
  dividirMatrizPromedio(matriz, promedio);
  float array[9];
  matrizAArray(matriz, array);
  mostrarPromedio(promedio);
  mostrarMatriz(matriz);
  mostrarArray(array);
}