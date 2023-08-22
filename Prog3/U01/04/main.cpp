#include <iostream>

int mcd(int, int);

int main() { std::cout << mcd(16, 32); }

int mcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return mcd(b, a % b);
  }
}
