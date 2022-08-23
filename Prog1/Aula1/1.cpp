#include <iostream>

float cuantaDistancia(float velocidad, float tiempo)
{
  return velocidad * tiempo;
}

int main()
{
  float velocidad, tiempo;

  std::cin >> velocidad >> tiempo;
  std::cout << cuantaDistancia(velocidad, tiempo) << std::endl;
}