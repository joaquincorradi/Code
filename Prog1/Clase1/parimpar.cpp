#include <iostream>

void esPar(int n)
{
  if (n == 0)
  {
    std::cout << "Es cero. \n";
  }

  int divNum = n % 2;

  if (divNum == 0 && n != 0)
  {
    std::cout << "Es par. \n";
  }
  else if (divNum != 0 && n != 0)
  {
    std::cout << "Es impar \n";
  }
}

int main()
{
  int n;

  std::cout << "Ingrese un numero: ";
  std::cin >> n;

  esPar(n);
}
