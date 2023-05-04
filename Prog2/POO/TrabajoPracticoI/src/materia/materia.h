#ifndef _MATERIAH_
#define _MATERIAH_

#include <string>

class materia {
protected:
  int codigo;
  std::string nombre;
  int nota;
  std::string titular;

public:
  materia(int x, std::string);

  void setCodigo(int x);
  void setNombre(std::string x);
  void setNota(int x);

  int getCodigo();
  std::string getNombre();
  int getNota();
};

#endif // !_MATERIAH_
