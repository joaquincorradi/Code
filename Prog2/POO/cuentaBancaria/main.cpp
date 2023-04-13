#include "../cuentaBancaria/cuenta.h"
#include <iostream>

int main() {
  cuenta t("Joaquin", 20.0);
  std::cout << "La cuenta del titular: " << t.getTitularCuenta()
            << " posee un balance de: $" << t.getCantidadDinero() << '\n';
}
