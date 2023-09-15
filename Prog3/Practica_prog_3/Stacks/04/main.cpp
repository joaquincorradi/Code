#include <iostream>
#include <stack>
#include <string>

bool estaBalanceada(std::string);

int main() {
  std::string funcion;

  std::cout
      << "Ingrese una función matemática para chequear si está balanceada: ";
  getline(std::cin, funcion);

  if (estaBalanceada(funcion)) {
    std::cout << "\nLa función está balanceada.\n";
  } else {
    std::cout << "\nLa función no está balanceada.\n";
  }

  return 0;
}

bool estaBalanceada(std::string funcion) {
  std::stack<char> pila;

  for (int i = 0; i < funcion.size(); i++) {
    if (funcion[i] == '(' || funcion[i] == '[' || funcion[i] == '{') {
      pila.push(funcion[i]);
    }

    if (funcion[i] == ')' || funcion[i] == ']' || funcion[i] == '}') {
      if (pila.empty()) {
        return false;
      }

      if ((pila.top() == '(' && funcion[i] == ')') ||
          (pila.top() == '[' && funcion[i] == ']') ||
          (pila.top() == '{' && funcion[i] == '}')) {
        pila.pop();
      } else {
        return false;
      }
    }
  }

  return pila.empty();
}
