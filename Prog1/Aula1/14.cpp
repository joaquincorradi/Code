#include <iostream>

void parImpar(int n)
{
  if (n % 2 == 0 && n != 0)
  {
    std::cout << "Es par." << "\n";
  }
  else if (n % 2 == 1 && n != 0)
  {
    std::cout << "Es impar." << "\n";
  }
  else
  {
    std::cout << "Es cero." << "\n";
  }
}

int main()
{
  int n;

  std::cin >> n;
  parImpar(n);
}