#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "../banco/banco.h"
#include "../cajaSeguridad/cajaSeguridad.h"
#include <string>

class sucursal : public banco {
private:
  int numeroDeSucursal;
  std::string responsableDeSucursal;

public:
  cajaSeguridad CajaSeguridad;
  sucursal(std::string, int, std::string);

  int getNumeroDeSucursal();
  std::string getResponsableDeSucursal();

  void setNumeroDeSucursal(int);
  void setResponsableDeSucursal(std::string);

  void imprimir();
};

#endif
