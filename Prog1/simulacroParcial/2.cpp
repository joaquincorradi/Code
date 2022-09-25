#include <iostream>

void ingresarMatriz(int m[3][3])
{
  std::cout << "Ingrese matriz: ";
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << "Columna " << i + 1 << ": ";
    for (int j = 0; j <= 2; ++j)
    {
      std::cin >> m[i][j];
    }
    std::cout << '\n';
  }
}

void diagonalPrincipal(int m[3][3], int dp[3], int ds[3])
{
  
}

int main()
{
  int m[3][3], dp[3], ds[3]; 
  ingresarMatriz(m);
}
