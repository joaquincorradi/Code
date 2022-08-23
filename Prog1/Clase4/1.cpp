#include <iostream>

void mensajeBienvenida(std::string mensaje, char c)
{
  for (int i = 0; i < 10; ++i)
  {
    std::cout << " " << c << " ";
  }
  std::cout << "\n";
  std::cout << "\t" << mensaje << std::endl;

  for (int i = 0; i < 10; ++i)
  {
    std::cout << " " << c << " ";
  }

  std::cout << "\n";
}

int main()
{
  std::string mensaje;
  char c;

  std::cin >> mensaje >> c;

  mensajeBienvenida(mensaje, c);
}