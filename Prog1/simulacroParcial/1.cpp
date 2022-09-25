#include <iostream>

void cargarArray(int a[5])
{
  std::cout << "Ingrese el arreglo: ";
  for (int i = 0; i <= 4; ++i)
  {
    std::cin >> a[i];
  }
}

void unirArray(int a1[5], int a2[5], int aa[10])
{
  for (int i = 0; i <= 4; ++i)
  {
    aa[i] = a1[i];
  }
  for (int j = 5; j <= 9;++j)
  {
    aa[j] = a2[j - 5];
  }
}

void ordernarArray(int aa[10])
{
  int guardarTemporal;
  for (int i = 0; i <= 9; ++i)
  {
    for (int j = i + 1; j <= 9; ++j)
    {
      if (aa[i] > aa[j])
      {
        guardarTemporal = aa[i];
        aa[i] = aa[j];
        aa[j] = guardarTemporal;
      }
    }
  }
}

void imprimirArray(int aa[10])
{
  std::cout << "El array ordenado es: " << '\n';
  std::cout << "[ ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cout << " " << aa[i] << " ";
  }
  std::cout << " ]" << '\n';
}

int main()
{
  int a1[5], a2[5], aa[10];

  cargarArray(a1);
  cargarArray(a2);
  unirArray(a1, a2, aa);
  ordernarArray(aa);
  imprimirArray(aa);
}
