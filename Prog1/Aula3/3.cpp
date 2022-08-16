#include <iostream>

void cualMayor (float n1, float n2)
{
  if (n1 == n2)
  {
    std::cout << "Son iguales." << "\n";
  }
  else if (n1 < n2)
  {
    std::cout << n2 << " es mayor." << "\n";
  }
  else if (n1 > n2)
  {
    std::cout << n1 << " es mayor." << "\n";
  }
}

int main ()
{
  float n1, n2;

  std::cin >> n1 >> n2;
  cualMayor(n1, n2);
}
