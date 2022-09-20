#include <iostream>

void pasarNumeros(int num[10])
{
  int contador;
  for (int i = 0; i <= 9; ++i)
  {
    if (num[i] < 5)
    {
      contador++;
    }
  }
  std::cout << "Cantidad de numeros menores a 5: " << contador << "\n";
}

int main()
{
  int num[10];

  for (int i = 0; i < 9; ++i)
  {
    std::cin >> num[i];
  }

  pasarNumeros(num);
}
