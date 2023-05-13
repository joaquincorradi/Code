#include "src/sucursal/sucursal.h"
#include <iostream>

int main() {
  sucursal *Sucursal;
  Sucursal = new sucursal("Santander", 25, "Corradi");
  Sucursal->CajaSeguridad.setCodigo(4837);

  Sucursal->imprimir();

  delete Sucursal;
}
