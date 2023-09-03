#include "../01/lista.h"
#include <iostream>

int main() {
  Lista<float> list;

  float numero;
  std::string entrada;

  std::cout
      << "Ingrese los números de la lista (ingrese 'fin' para finalizar): ";

  while (true) {
    std::cin >> entrada;

    if (entrada == "fin") {
      std::cout << "\nSe terminó de ingresar la lista.\n";
      break;
    }

    try {
      // Intento convertir la entrada a un número flotante
      numero = std::stod(entrada);
      list.insertarUltimo(numero);
    } catch (const std::exception &e) {
      std::cout << "Entrada no válida. Ingrese un número válido o 'fin' para "
                   "finalizar.\n";
    }
  }

  std::cout << "Lista actual: ";
  list.imprimir();

  std::cout << "\nIngrese un número no entero para agregar a la lista: ";
  std::cin >> numero;

  int opcion;
  std::cout
      << "Desea agregarlo al principio (1), al final (2) o en el medio (3)? ";
  std::cin >> opcion;

  if (opcion == 1) {
    list.insertarPrimero(numero);
  } else if (opcion == 2) {
    list.insertarUltimo(numero);
  } else if (opcion == 3) {
    int posicion;
    std::cout << "Ingrese la posición donde desea agregar el número: ";
    std::cin >> posicion;
    try {
      list.insertar(posicion, numero);
    } catch (int e) {
      std::cout << "Posición inválida." << std::endl;
    }
  }

  std::cout << "\nLista actualizada: ";
  list.imprimir();

  return 0;
}
