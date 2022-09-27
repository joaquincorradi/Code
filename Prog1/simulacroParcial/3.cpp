//f[000111222]
//c[012012012]
//datos[7,6,9,8,4,17,23,1,14]

#include <iostream>

/*void ingresarArray(int array[9])
{
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= 8; ++i)
  {
    std::cin >> array[i];
  }
}*/

void crearMatriz(int filas[9], int columnas[9], int datos[9], int matriz[3][3])
{
  for (int i = 0; i <= 8; ++i)
  {
    matriz[filas[i]][columnas[i]] = datos[i]; 
  }
}

void mostrarMatriz(int matriz[3][3])
{
  std::cout << "Matriz resultante: ";
  std::cout << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    for (int j = 0; j <= 2; ++j) 
    { 
      std::cout << "  " << matriz[i][j] << "  ";
    }
    std::cout << '\n';
  }
}

int main()
{
  int filas[9]={0,0,0,1,1,1,2,2,2}, columnas[9]={0,1,2,0,1,2,0,1,2}, datos[9]={7,6,9,8,4,17,23,1,14}, matriz[3][3];
  // ingresarArray(filas);
  // ingresarArray(columnas);
  // ingresarArray(datos);
  crearMatriz(filas, columnas, datos, matriz);
  mostrarMatriz(matriz);
}
