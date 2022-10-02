#include <iostream>

void cargarMatriz(int matriz[3][3])
{
  std::cout << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << "Ingrese fila " << i + 1 << ": ";
    for (int j = 0; j <= 2; ++j)
    {
      std::cin >> matriz[i][j];
    }
  }
  std::cout << '\n';
}

void sumarF(int fls[3], int matriz[3][3])
{
  int suma = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      suma += matriz[i][j];
    }
    fls[i] = suma;
    suma = 0;
  }
}

void sumarC(int cls[3], int matriz[3][3])
{
  int suma = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      suma += matriz[j][i];
    }
    cls[i] = suma;
    suma = 0;
  }
}

int calcPromedio(int array[3])
{
  int promedio = 0;
  for (int i = 0; i <= 2; ++i)
  {
    promedio += array[i];
  }
  promedio /= 3;
  return promedio;
}

int checkPromedio(int promedio, int array[3])
{
  int contador = 0;
  for (int i = 0; i <= 2; ++i)
  {
    if (array[i] < promedio)
    {
      ++contador;
    }
  }
  return contador;
}

void mostrarMatriz(int matriz[3][3])
{
  std::cout << "La matriz ingresada es: " << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      std::cout << " " << matriz[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

void mostrarArray(int array[3])
{
  std::cout << '\n';
  std::cout << "El array es: [ ";
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << " ]" << '\n';
}

void mostrarResultados(int promedio, int menores)
{
  std::cout << "El promedio es: " << promedio << ", y hay " << menores << " elementos menores a este." << '\n';
}

int main()
{
  int matriz[3][3], sumaFilas[3], sumaColumnas[3];
  cargarMatriz(matriz);
  sumarF(sumaFilas, matriz);
  sumarC(sumaColumnas, matriz);
  int promedioFilas = calcPromedio(sumaFilas);
  int promedioColumnas = calcPromedio(sumaColumnas);
  int numerosMenoresFilas = checkPromedio(promedioFilas, sumaFilas);
  int numerosMenoresColumnas = checkPromedio(promedioColumnas, sumaColumnas);
  mostrarMatriz(matriz);
  std::cout << "Suma de filas: ";
  mostrarArray(sumaFilas);
  mostrarResultados(promedioFilas, numerosMenoresFilas);
  std::cout << '\n';
  std::cout << "Suma de columnas: ";
  mostrarArray(sumaColumnas);
  mostrarResultados(promedioColumnas, numerosMenoresColumnas);
  std::cout << '\n';
}