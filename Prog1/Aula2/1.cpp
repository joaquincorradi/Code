#include <iostream>

float calcPerimetro(float base, float altura)
{
  return 2. * (base + altura);
}

float calcArea(float base, float altura)
{
  return base * altura;
}

int main()
{
  float base, altura;
  char respuesta;
  while (respuesta == 's')
  {
    while (base < 0 || altura < 0) 
    {
      std::cin >> base >> altura;
    }

  }
  while (base < 0 || altura < 0)
  {
    std::cin >> base >> altura;
  }
  std::cout << calcPerimetro(base, altura) << std::endl;
  std::cout << calcArea(base, altura) << std::endl;
}
