#include <iostream>
#include <stack>
#include <string>

int calcularPrioridad(char);
void convertirAPostfijo(std::string);

int main() {
  std::string funcion;

  std::cout << "Ingrese una función infija para convertir a postfijo: ";
  getline(std::cin, funcion);

  convertirAPostfijo(funcion);

  return 0;
}

int calcularPrioridad(char operador) {
  if (operador == '^')
    return 3;
  else if (operador == '/' || operador == '*')
    return 2;
  else if (operador == '+' || operador == '-')
    return 1;
  else
    return -1;
}

void convertirAPostfijo(std::string expresionInfija) {
  std::stack<char> pila;
  std::string expresionPostfija;
  char caracter = ' ';

  for (int i = 0; i < expresionInfija.size(); i++) {
    caracter = expresionInfija[i];

    /* Si el caracter escaneado es un operando entonces se agrega a la expresion
     * postfija */
    if ((caracter >= 'a' && caracter <= 'z') ||
        (caracter >= 'A' && caracter <= 'Z') ||
        (caracter >= '0' && caracter <= '9')) {
      expresionPostfija += caracter;
    }

    /* Si el caracter escaneado es un '(' entonces se agrega a la pila */
    if (caracter == '(') {
      pila.push(caracter);
    }

    /* Si el caracter escaneado es un ')' entonces se agrega a la pila hacer pop
     */
    if (caracter == ')') {
      while (pila.top() != '(') {
        expresionPostfija += pila.top();
        pila.pop();
      }
      pila.pop();
    }
  }
}

/*
Input:    A+B*C+D
Output:   ABC*+D+
*/