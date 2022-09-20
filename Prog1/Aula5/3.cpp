#include <iostream>

void tamanoArray(int &n)
{
  std::cout << "Ingrese el tamano del array: ";
  std::cin >> n;
}

void ingresoArray(int n, int num[])
{
  std::cout << "Ingrese el array: ";
  for (int i = 0; i <= n - 1; ++i)
  {
    std::cin >> num[i];
  }
}

void eliminarCeros(int n, int num[])
{
  int contador = 0;
  int sinCeros[n];
  for (int i = 0; i <= n - 1; ++i)
  {
    if (num[i] != 0)
    {
      sinCeros[contador] = num[i];  
      ++contador;
    }
  }

  std::cout << "[ ";
  for (int j = 0; j <=contador - 1; ++j)
  {
    std::cout << " " <<sinCeros[j] << " ";
  }
  std::cout << " ]";
  std::cout << '\n';
}

int main()
{
  int n;
  tamanoArray(n);
  int num[n];
  ingresoArray(n, num);
  eliminarCeros(n, num);
}
