#include <iostream>

void tamanoVector(int &tamano)
{
  std::cout << '\n';
  std::cout << "Ingrese tamano del vector: ";
  std::cin >> tamano;
}

void ingresarVector(int tamano, int array[])
{
  std::cout << '\n';
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= tamano - 1; ++i)
  {
    std::cin >> array[i];
  }
}

void mostrarVector(int array[], int tamano)
{
  std::cout << '\n';
  std::cout << "El vector es: [";
  for (int i = 0; i <= tamano - 1; ++i)
  {
    std::cout << " " << array[i] << " ";
  }
  std::cout << "]";
}

int productoPunto(int vector1[], int vector2[], int tamano)
{
  int producto = 0;
  for (int i = 0; i <= tamano - 1; ++i)
  {
    producto += (vector1[i] * vector2[i]);
  }
  return producto;
}

void mostrarResultado(int producto)
{
  std::cout << '\n';
  std::cout << "El producto punto es: " << producto << '\n';
  std::cout << '\n';
}

int main()
{
  int tamano = 0;
  tamanoVector(tamano);
  int vector1[tamano], vector2[tamano];
  ingresarVector(tamano, vector1);
  ingresarVector(tamano, vector2);
  std::cout << "Primer vector: ";
  mostrarVector(vector1, tamano);
  std::cout << "Segundo vector: ";
  mostrarVector(vector2, tamano);
  int productoEscalar = productoPunto(vector1, vector2, tamano);
  mostrarResultado(productoEscalar);
}