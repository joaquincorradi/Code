#include <iostream>

void promedio(int d1, int d2, int d3, int d4, int d5)
{
  float prom = (d1 + d2 + d3 + d4 + d5) / 5.;
  if (prom > 100 && prom < 200)
  {
    std::cout << "Supera 100" << std::endl;
  }
  else if (prom > 200 && prom < 300)
  {
    std::cout << "Supera 200" << std::endl; 
  }
  else if (prom > 300)
  {
    std::cout << "Supera 300" << std::endl; 
  }
}

int main()
{
  int d1, d2, d3, d4, d5;

  std::cin >> d1 >> d2 >> d3 >> d4 >> d5;
  promedio(d1, d2, d3, d4, d5);
}