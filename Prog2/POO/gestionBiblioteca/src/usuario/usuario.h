#ifndef USUARIO_H
#define USUARIO_H

#include "../libro/libro.h"
#include <string>

class usuario {
private:
  std::string nombreDeUsuario;
  int numeroDeIdentificacion;

public:
  libro *LibroEnUsuario;
  usuario(std::string, int);

  std::string getNombreDeUsuario();
  int getNumeroDeIdentificacion();

  void setNombreDeUsuario(std::string);
  void setNumeroDeIdentificacion(int);

  void agregarNuevoUsuario();
};

#endif
