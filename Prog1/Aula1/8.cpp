#include <iostream>
#include <string>

bool checkEdad(int aa)
{
  bool menor;

  if ((2022 - aa) <= 18)
  {
    menor = true;
  }

  return menor;
}

int main()
{
  std::string nombre;
  int aa;
 
  std::cin >> nombre >> aa;

  bool funcMenor = checkEdad(aa);

  if (funcMenor)
  {
    std::cout << nombre << " puede acceder al beneficio impositivo." << "\n";
  }
  else
  {
    std::cout << nombre << " no puede acceder al beneficio impositivo." << "\n";
  }
}