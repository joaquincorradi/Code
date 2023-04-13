#include "../cuentaBancaria/cuenta.h"
#include <string>

cuenta::cuenta(std::string titular) { titularCuenta = titular; }
cuenta::cuenta(std::string titular, double cantidad) {
  titularCuenta = titular, cantidadDinero = cantidad;
}
std::string cuenta::getTitularCuenta() { return titularCuenta; }
int cuenta::getCantidadDinero() { return cantidadDinero; }
void cuenta::ingresarDinero(double n) {
  if (n >= 0) {
    cantidadDinero += n;
  }
}
void cuenta::retirarDinero(double m) {
  cantidadDinero -= m;
  if (cantidadDinero < 0) {
    cantidadDinero = 0;
  }
}
