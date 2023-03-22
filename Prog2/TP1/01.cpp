#include <iostream>

float calcSaltosMinimos(float x, float y, float d);

int main() {
  int x, y, d;
  std::cin >> x >> y >> d;
  float minimo = calcSaltosMinimos(x, y, d);
  std::cout << minimo << '\n';
}

float calcSaltosMinimos(float x, float y, float d) { return (y - x) / d; }
