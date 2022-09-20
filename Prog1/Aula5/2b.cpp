//corregir
#include <iostream>

void arrayAux(int n, int num[])
{
  int negativos[n], contadorNegativos = 0;
  int positivos[n], contadorPositivos= 0;

  for (int i = 0; i <= n - 1; ++i)
  {
    if (num[i] < 0)
    {
      negativos[contadorNegativos] = num[i];
      ++contadorNegativos;
    }
  }

  for (int l = 0; l <= n - 1; ++l)
  {
    if (num[l] > 0)
    {
      positivos[contadorPositivos] = num[l];
      ++contadorPositivos;
    }
  }
  
  std::cout << "Negativos: [";
  for (int j = 0; j <= contadorNegativos - 1; ++j)
  {
    std::cout << " " << negativos[j] << " ";
  }
  std::cout << "]" << '\n';

  std::cout << "Positivos: [";
  for (int k = 0; k <= contadorPositivos - 1; ++k)
  {
    std::cout << " " << positivos[k] << " "; 
  }
  std::cout << "]" << '\n';
}

int main()
{
  int n;
  std::cout << "Ingresar tamano del array: ";
  std::cin >> n;
 
  int num[n];
  
  std::cout << "Ingrese numeros: ";
  for (int i = 0; i <= n - 1; ++i)
  {
    std::cin >> num[i]; 
  }

  arrayAux(n, num);
}
