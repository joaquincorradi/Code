#include <iostream>

float promedioAplazos(float n1, float n2, float n3, float &promedio, int &aplazos)
{
  promedio = (n1 + n2 + n3) / 3;
  aplazos = 0;
  if (n1 < 6)
  {
    ++aplazos;
  }
  if (n2 < 6)
  {
    ++aplazos;
  }
  if (n3 < 6)
  {
    ++aplazos;
  }
  return 0.;
}

int main()
{
  float n1, n2, n3, promedio;
  int aplazos;
  std::string legajo;
  int a, i = 0;

  std::cout << "Numero de alumnos: ";
  std::cin >> a;
  while (i < a)
  {
    std::cout << "Notas: ";
    std::cin >> n1 >> n2 >> n3;
    std::cout << "Legajo: ";
    std::cin >> legajo;
    float func = promedioAplazos(n1, n2, n3, promedio, aplazos);
    
    std::cout << "El alumno " << legajo << " tiene promedio: " << promedio <<
     " y " << aplazos << " aplazos." << "\n"; 
  ++i;
  }
}