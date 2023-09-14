#include <iostream>
#include <stack>

bool sonIguales(std::stack<char> pila1, std::stack<char> pila2);

int main() {
  std::stack<char> pila1, pila2;
  char caracter = ' ';

  std::cout << "Ingrese la primer pila para ser comparada. Termine con "
               "punto (.): ";

  while (true) {
    std::cin >> caracter;
    if (caracter == '.') {
      break;
    } else {
      pila1.push(caracter);
    }
  }

  std::cout
      << "Ingrese la segunda pila para ser comparada. Termine con punto (.): ";

  while (true) {
    std::cin >> caracter;
    if (caracter == '.') {
      break;
    } else {
      pila2.push(caracter);
    }
  }

  if (sonIguales(pila1, pila2)) {
    std::cout << "\nLas pilas son iguales.\n";
  } else {
    std::cout << "\nLas pilas son diferentes.\n";
  }

  return 0;
}

bool sonIguales(std::stack<char> pila1, std::stack<char> pila2) {
  while (!pila1.empty() && !pila2.empty()) {
    if (pila1.top() != pila2.top()) {
      return false;
    } else {
      pila1.pop();
      pila2.pop();
    }
  }

  return pila1.empty() && pila2.empty();
}