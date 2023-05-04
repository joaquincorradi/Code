#include "./persona.h"
#include <iostream>

persona::persona(int x, std::string y, std::string z, std::string w) {
  dni = x;
  nombre = y;
  apellido = z;
  mail = w;
}

void persona::setDni(int x) { dni = x; }
void persona::setNombre(std::string x) { nombre = x; }
void persona::setApellido(std::string x) { apellido = x; }
void persona::setMail(std::string x) { mail = x; }

int persona::getDni() { return dni; }
std::string persona::getNombre() { return nombre; }
std::string persona::getApellido() { return apellido; }
std::string persona::getMail() { return mail; }

void persona::modificarDatos() {
  std::cout << "Ingrese su DNI: ";
  std::cin >> dni;
  std::cout << "Ingrese su nombre: ";
  std::cin >> nombre;
  std::cout << "Ingrese su apellido: ";
  std::cin >> apellido;
  std::cout << "Ingrese su email: ";
  std::cin >> mail;
}
