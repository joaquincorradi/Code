#include <iostream>

void ingresarMatriz(int matriz[3][3])
{
  std::cout << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << "Ingrese la fila " << i + 1;
    for (int j = 0; j <= 2; ++j)
    {
      std::cin >> matriz[i][j];
    }
  }
}
