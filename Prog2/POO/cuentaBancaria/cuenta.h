#include <string>

class cuenta {
  std::string titularCuenta;
  double cantidadDinero;

public:
  cuenta(std::string titular);
  cuenta(std::string titular, double cantidad);
  std::string getTitularCuenta();
  int getCantidadDinero();
  void ingresarDinero(double n);
  void retirarDinero(double n);
};
