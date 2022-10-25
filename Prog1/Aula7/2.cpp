#include <iostream>
#include <fstream>

void contar(std::ifstream &datos);

int main()
{
  std::ifstream datos("datos2.txt");
  contar(datos);
}

void contar(std::ifstream &datos)
{
  int contador = 0;
  std::string a[100];
  while (datos >> a[contador])
  {
    ++contador;
  }
  std::cout << "Hay " << contador << " elementos" << '\n';
}