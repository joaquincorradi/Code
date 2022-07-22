#include <iostream>

void DrawTrian(int b, char sym);

int main()
{
  int b;
  char sym;

  std::cout << "Base: ";
  std::cin >> b;
  std::cout << "Simbolo: ";
  std::cin >> sym;

  DrawTrian(b, sym);
}

void DrawTrian(int b, char sym)
{
  for (int i = 1; i < b + 1; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      std::cout << sym << "  ";
    }
    std::cout << '\n';
  }
}