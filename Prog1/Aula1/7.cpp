#include <iostream>

void alarma(float temperatura)
{
  if (temperatura > 80)
  {
    std::cout << "\tALARMA!!!" << "\n";
  }
}

int main()
{
  float temperatura;

  std::cin >> temperatura;
  alarma(temperatura);
}