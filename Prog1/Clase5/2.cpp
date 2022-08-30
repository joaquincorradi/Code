#include <iostream>

float calcMonto(float sueldo, float &descJubilacion, float &descOS, float &sueldoNeto)
{
  descJubilacion *= sueldo / 100;
  descOS *= sueldo / 100;
  sueldoNeto = (sueldo - descJubilacion) - descOS; 
  
  return 0.;
}

int main()
{
  float sueldo, descJubilacion, descOS, sueldoNeto;
  std::cin >> sueldo >> descJubilacion >> descOS;

  float func = calcMonto(sueldo, descJubilacion, descOS, sueldoNeto);

  std::cout << "El sueldo es: $" << sueldo << "\n" ;
  std::cout << "El descuento por jubilacion es: $" << descJubilacion << "\n";
  std::cout << "El descuento por obra social es: $" << descOS << "\n";
  std::cout << "El sueldo neto es: $" << sueldoNeto << "\n";
}