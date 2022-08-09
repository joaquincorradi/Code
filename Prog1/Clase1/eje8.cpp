#include <iostream>

bool checkEdad(int aa)
{
  bool mayor;
  if ((2022 - aa) >= 18)
  {
    mayor = true;
  }
  return mayor;
}

int main()
{
  int aa;
  bool varmayor= checkEdad(aa);

  std::cin >> aa;
  if (varmayor)
  {
    std::cout << "Legal" << std::endl;
  }
  else {
  {
    std::cout << "Ilegal" << std::endl;
  }
  }
}