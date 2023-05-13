#include "./cajaSeguridad.h"

cajaSeguridad::cajaSeguridad() {}
cajaSeguridad::cajaSeguridad(int _codigo) { codigo = _codigo; }

int cajaSeguridad::getCodigo() { return codigo; }

void cajaSeguridad::setCodigo(int _codigo) { codigo = _codigo; }
