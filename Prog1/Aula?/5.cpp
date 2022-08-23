#include <iostream>

float montoPagar(int cant, float precio, float descuento)
{  
  float valorDescuento = (descuento * (cant * precio)) / 100;
  float pagarFinal = (cant * precio) - valorDescuento;
  return pagarFinal;
}

int main()
{
  int cant;
  float precio, descuento;

  std::cin >> cant >> precio >> descuento;
  std::cout << montoPagar(cant, precio, descuento) << std::endl;
}