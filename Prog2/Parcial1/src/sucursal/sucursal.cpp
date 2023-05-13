#include "./sucursal.h"
#include <iostream>
#include <string>

sucursal::sucursal(std::string _nombreDelBanco, int _numeroDeSucursal,
                   std::string _responsableDeSucursal)
    : banco(_nombreDelBanco) {
  responsableDeSucursal = _responsableDeSucursal;
  numeroDeSucursal = _numeroDeSucursal;
}
int sucursal::getNumeroDeSucursal() { return numeroDeSucursal; }
std::string sucursal::getResponsableDeSucursal() {
  return responsableDeSucursal;
}

void sucursal::setNumeroDeSucursal(int _numeroDeSucursal) {
  numeroDeSucursal = _numeroDeSucursal;
}
void sucursal::setResponsableDeSucursal(std::string _responsableDeSucursal) {
  responsableDeSucursal = _responsableDeSucursal;
}

void sucursal::imprimir() {
  std::cout << numeroDeSucursal << '\n';
  std::cout << responsableDeSucursal << '\n';
  std::cout << CajaSeguridad.getCodigo() << '\n';
  std::cout << getNombreDelBanco();
}
