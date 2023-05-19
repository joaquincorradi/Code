#include <iostream>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int *p1 = array;
  int *p2 = array;

  std::cout << p1[0] << '\n';
  std::cout << p2[4] << '\n';
}
