#ifndef CAJASEGURIDAD_H
#define CAJASEGURIDAD_H

class cajaSeguridad {
private:
  int codigo;

public:
  cajaSeguridad();
  cajaSeguridad(int);

  int getCodigo();

  void setCodigo(int);
};

#endif
