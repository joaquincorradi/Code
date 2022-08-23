#include <iostream>

void cualSigno (float n)
{
  
  if (n < 0)
  {
    std::cout << "Negativo." << "\n";
  }
  else if (n > 0)
  {
    std::cout << "Positivo." << "\n";
  }
  else
  {
    std::cout << "Es cero." << "\n";
  }
}

int main()
{
  float n;

  std::cin >> n;
  cualSigno(n);
}