#include <iostream>

void mostrarMatriz(int matriz[3][3])
{
  std::cout << '\n';
  std::cout << "La matriz es: " << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      std::cout << " " << matriz[i][j] << " ";
    }
    std::cout << '\n';
  }
}
