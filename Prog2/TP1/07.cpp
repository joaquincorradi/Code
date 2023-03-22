#include <iostream>

void intercambiarVariable(int x, int y);

int main() {
  int x, y;
  std::cin >> x >> y;
  intercambiarVariable(x, y);
}

void intercambiarVariable(int x, int y) {
  int temp = 0;
  temp = x;
  x = y;
  y = temp;
  std::cout << "X = " << x << ", Y = " << y << '\n';
}
