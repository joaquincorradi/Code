#include <iostream>

void reemplazarMenoresPromedio(int num[10])
{
  float promedio;
  for (int i = 0; i <= 9; ++i)
  {
    promedio += num[i];  
  }
  
  promedio /= 10;

  for (int j = 0; j <= 9; ++j)
  {
    if (num[j] < promedio)
    {
      num[j] = -1;
    }
  }

  std::cout << "El promedio es: " << promedio << '\n';
  
  std::cout << "[ ";
  for (int k = 0; k <= 9; ++k)
  {
    std::cout << " " <<num[k] << " ";
  }
  std::cout << " ]" << '\n';
}

int main()
{
  int num[10];

  std::cout << "Ingrese numeros: ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cin >> num[i]; 
  }

  reemplazarMenoresPromedio(num);
}
