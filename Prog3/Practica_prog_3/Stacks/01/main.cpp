#include <iostream>
#include <stack>

void imprimirInvertido(std::stack<char> palabra);

int main() {
  std::stack<char> palabra;
  char caracter = ' ';

  std::cout << "Ingrese una palabra y se imprimirá invertida. Termine con "
               "punto (.): ";

  while (true) {
    std::cin >> caracter;
    if (caracter == '.') {
      break;
    } else {
      palabra.push(caracter);
    }
  }

  imprimirInvertido(palabra);

  return 0;
}

void imprimirInvertido(std::stack<char> palabra) {
  std::cout << "\nPalabra invertida: ";

  while (!palabra.empty()) {
    std::cout << palabra.top();
    palabra.pop();
  }

  std::cout << '\n';
}