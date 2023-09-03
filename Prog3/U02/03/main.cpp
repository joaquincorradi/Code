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

  int posicion;
  std::cout << "\nIngrese la posición del elemento a eliminar (0 para el "
               "primero por la izquierda): ";
  std::cin >> posicion;

  try {
    list.eliminar(posicion);
    std::cout << "Elemento en la posición " << posicion << " eliminado.\n";
  } catch (int e) {
    std::cout << "Posición inválida." << std::endl;
  }

  std::cout << "Lista actual: ";
  list.imprimir();

  return 0;
}
