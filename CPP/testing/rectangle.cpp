#include <iostream>

void DrawRect(int h, int b, char sym);

int main()
{
  int h, b;
  char sym;

  std::cout << "Alto: ";
  std::cin >> h;
  std::cout << "Base: ";
  std::cin >> b;
  std::cout << "Simbolo: ";
  std::cin >> sym;
  
  DrawRect(h, b, sym);
}

void DrawRect(int h, int b, char sym)
{
  for(int i = 0; i < h; ++i)
  {
    for (int j = 0; j < b; ++j)
    {
     std::cout << sym << "  ";
    }
    
    std::endl(std::cout);
  }
}
