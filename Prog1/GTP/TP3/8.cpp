#include <iostream>

void ingresarMatriz(int matriz[2][2])
{
  std::cout << '\n';
  for (int i = 0; i <= 1; ++i)
  {
    std::cout << "Ingrese la fila " << i + 1 << ": ";
    for (int j = 0; j <= 1; ++j)
    {
      std::cin >> matriz[i][j];
    }
  }
}

int calcDeterminante(int matriz[2][2])
{
  return (matriz[0][0]*matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
}

void mostrarMatriz(int matriz[2][2], int determinante)
{
  std::cout << "La matriz ingresada es: ";
  std::cout << '\n';
  for (int i = 0; i <= 1; ++i)
  {
    for (int j = 0; j <= 1; ++j)
    {
      std::cout << " " << matriz[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << "Y su determinante es: " << determinante << '\n';
}


int main()
{
  int matriz[2][2];
  ingresarMatriz(matriz);
  int determinante = calcDeterminante(matriz);
  mostrarMatriz(matriz, determinante);
}