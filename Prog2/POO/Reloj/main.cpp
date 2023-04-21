#include "../Reloj/reloj.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <thread>

int main() {
  reloj r(14, 9, 0);
  int i = 0;

  while (i != 1) {
    ++r;
    std::cout << r.getHora() << " : " << r.getMinuto() << " : "
              << r.getSegundo() << '\n';
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
  }
}
