#include <iostream>
#include <fstream>

void imprimirDatos(std::ifstream &fdatos1);
void reordenarDatos(std::ifstream &datos1, std::ofstream &datos2);

int main()
{
  std::ifstream datos1("datos.txt");
  std::ofstream datos2("datos2.txt");

  imprimirDatos(datos1);
  reordenarDatos(datos1, datos2);
}

void imprimirDatos(std::ifstream &datos1)
{
  int a;
  std::cout << "[ ";
  while (datos1 >> a)
  {
    std::cout << a << " ";
  }
  std::cout << "]" << '\n';
  datos1.clear();
  datos1.seekg(0);
}

void reordenarDatos(std::ifstream &datos1, std::ofstream &datos2)
{
  int a;
  while (datos1 >> a)
  {
    datos2 << a << " ";
  }
}
