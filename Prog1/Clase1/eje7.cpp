#include <iostream>
#include <string>

void alarma (int temp)
{
  if (temp >= 80)
  {
    std::cout << "\tALARMA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
  }
}

int main()
{
  float temp;

  std::cin >> temp;
  alarma(temp);
}