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
  std::cin >> dni;
  std::cin >> nombre;
  std::cin >> apellido;
  std::cin >> mail;
}

void persona::consultarDatos() {
  std::cout << dni;
  std::cout << nombre;
  std::cout << apellido;
  std::cout << mail;
}
