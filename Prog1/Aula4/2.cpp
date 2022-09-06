#include <iostream>

void dibujarTriangulo(int h, char c)
{
  for (int i = 0; i < h; ++i)
  {
    if (i <= (h / 2) + 1)  //imprime hasta 4 (7)
    {
      for (int j = 0; j < i; ++j)
      {
        std::cout << " " << c << " ";
      }
    }
    else
    {
      for (int k = h / 2; k < ; --k)
      {
        std::cout << " " << c << " ";
      }
    }
    std::cout << "\n";
  }
}

int main()
{
  int h;
  char c;

  std::cin >> h >> c;
  dibujarTriangulo(h, c);
}