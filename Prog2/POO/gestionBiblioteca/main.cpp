#include "src/libro/libro.h"
#include "src/usuario/usuario.h"
#include <cstdlib>
#include <iostream>

void menu(int *pOpcionElegidaMenu);
void primeraOpcion(usuario *Usuario[5], int *pContadorPrimeraOpcion);
void segundaOpcion(libro *Libro[5], usuario *Usuario[5],
                   int *pOpcionElegidaSegundaOpcion, bool *pValorSegundaOpcion,
                   int *pOpcionElegidaSegundaOpcionB);

int main() {
  usuario *Usuario[5];
  for (int i = 0; i < 5; ++i) {
    Usuario[i] = new usuario("", 1234);
  }

  libro *Libro[5];
  for (int i = 0; i < 5; ++i) {
    Libro[i] = new libro("", "", 0000, false);
  }

  int opcionElegidaMenu;
  int *pOpcionElegidaMenu = &opcionElegidaMenu;

  int contadorPrimeraOpcion;
  int *pContadorPrimeraOpcion = &contadorPrimeraOpcion;
  *pContadorPrimeraOpcion = 0;

  int opcionElegidaSegundaOpcion;
  int *pOpcionElegidaSegundaOpcion = &opcionElegidaSegundaOpcion;
  int opcionElegidaSegundaOpcionB;
  int *pOpcionElegidaSegundaOpcionB = &opcionElegidaSegundaOpcionB;
  int contadorSegundaOpcion;
  int *pContadorSegundaOpcion = &contadorSegundaOpcion;
  *pContadorSegundaOpcion = 0;
  bool valorSegundaOpcion;
  bool *pValorSegundaOpcion = &valorSegundaOpcion;

  segundaOpcion(*Libro, *Usuario, *pOpcionElegidaSegundaOpcion,
                *pValorSegundaOpcion, *pOpcionElegidaSegundaOpcionB);

  for (int i = 0; i < 5; ++i) {
    delete Usuario[i];
    delete Libro[i];
  }
}

void menu(int *pOpcionElegidaMenu) {
  std::cout << "-- SISTEMA DE GESTION BIBLIOTECARIO --\n";
  std::cout << '\n';
  std::cout << "MENU PRINCIPAL\n";
  std::cout << "[1] Agregar nuevo usuario.\n";
  std::cout << "[2] Iniciar prestamo.\n";
  std::cout << "[3] Inciar devolucion.\n";
  std::cout << "[4] Agregar nuevo libro a la biblioteca.\n";
  std::cout << "[5] Mostrar informacion.\n";
  std::cout << "[6] Salir.\n";
  std::cout << "Seleccione una opcion: ";
  std::cin >> *pOpcionElegidaMenu;
}

void primeraOpcion(usuario *Usuario[5], int *pContadorPrimeraOpcion) {
  if (*pContadorPrimeraOpcion < 5) {
    Usuario[*pContadorPrimeraOpcion]->agregarNuevoUsuario();
    ++*pContadorPrimeraOpcion;
  } else {
    std::cout
        << "Se llego al numero maximo de usuarios disponibles por el sistema.";
  }
}

void segundaOpcion(libro *Libro[5], usuario *Usuario[5],
                   int *pOpcionElegidaSegundaOpcion, bool *pValorSegundaOpcion,
                   int *pOpcionElegidaSegundaOpcionB) {
  std::cout << "¿Cual es su nombre de usuario?\n";
  for (int i = 0; i < 5; ++i) {
    std::cout << "[" << i << "]" << Usuario[i]->getNombreDeUsuario() << '\n';
  }
  std::cout << "Elija una opcion: ";
  std::cin >> *pOpcionElegidaSegundaOpcionB;

  std::cout << "Los libros disponibles son: \n";
  for (int i = 0; i < 5; ++i) {
    std::cout << "[" << i << "] " << Libro[i]->getNombreDelLibro() << '\n';
  }
  std::cout << "Elija una opcion: ";
  std::cin >> *pOpcionElegidaSegundaOpcion;

  Libro[*pOpcionElegidaSegundaOpcion]->iniciarPrestamo(*pValorSegundaOpcion);
  if (*pValorSegundaOpcion) {
    Usuario[*pOpcionElegidaSegundaOpcionB]->LibroEnUsuario->getNombreDelLibro();
  }
}
