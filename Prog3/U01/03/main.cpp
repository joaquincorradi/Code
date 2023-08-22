#include <iostream>

int ackerman(int, int);

int main() {
  int ack = ackerman(3, 2);
  std::cout << ack;
}

int ackerman(int m, int n) {
  if (m == 0) {
    return n + 1;
  }

  if (m > 0 && n == 0) {
    return ackerman(m - 1, 1);
  }

  if (m > 0 && n > 0) {
    return ackerman(m - 1, ackerman(m, n - 1));
  }
  return 0;
}
