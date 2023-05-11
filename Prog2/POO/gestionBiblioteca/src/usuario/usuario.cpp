#include "./usuario.h"
#include <iostream>
#include <string>

libro::libro() {}

usuario::usuario(std::string _nombreDeUsuario, int _numeroDeIdentificacion) {
  nombreDeUsuario = _nombreDeUsuario;
  numeroDeIdentificacion = _numeroDeIdentificacion;
}

std::string usuario::getNombreDeUsuario() { return nombreDeUsuario; }
int usuario::getNumeroDeIdentificacion() { return numeroDeIdentificacion; }

void usuario::setNombreDeUsuario(std::string _nombreDeUsuario) {
  nombreDeUsuario = _nombreDeUsuario;
}
void usuario::setNumeroDeIdentificacion(int _numeroDeIdentificacion) {
  numeroDeIdentificacion = _numeroDeIdentificacion;
}

void usuario::agregarNuevoUsuario() {
  std::cout << "-- AGREGAR NUEVO USUARIO --\n";
  std::cout << '\n';
  std::cout << "Ingrese un nombre de usuario: ";
  std::cin >> nombreDeUsuario;
  do {
    std::cout << "Ingrese un nro. de identificacion [max. 4 nros.]: ";
    std::cin >> numeroDeIdentificacion;
  } while (nombreDeUsuario.length() <= 4);
  std::cout << "¡Usuario registrado con exito!\n";
}
