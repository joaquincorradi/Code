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

void ingresarNumero(int &numero)
{
  std::cout << '\n';
  std::cout << "Ingrese un numero por el que desea dividir la matriz: ";
  std::cin >> numero;
}

void dividirMatriz(float matriz[3][3], int numero)
{
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      matriz[i][j] /= numero;
    }
  }
}

int contarElementosMenores(float matriz[3][3])
{
  int contador = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      if (matriz[i][j] < 1)
      {
        ++contador;
      }
    }
  }
  return contador;
}

void elementosMenores(float matriz[3][3], float array[])
{
  int contador = 0;
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j)
    {
      if (matriz[i][j] < 1)
      {
        array[contador] = matriz[i][j];
        ++contador;
      }
    }
  }
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

void mostrarArray(float array[], int nroMenores)
{
  std::cout << '\n';
  std::cout << "La cantidad de numeros menores a 1 es " << nroMenores <<'\n';
  std::cout << "El array resultante es: [";
  for (int i = 0; i <= nroMenores - 1; ++i)
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
  int numero = 0;
  ingresarNumero(numero);
  dividirMatriz(matriz, numero);
  int nroMenores = contarElementosMenores(matriz);
  float array[nroMenores];
  elementosMenores(matriz, array);
  mostrarMatriz(matriz);
  mostrarArray(array, nroMenores);
}