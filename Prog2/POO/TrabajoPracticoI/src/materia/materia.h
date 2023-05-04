#ifndef _MATERIAH_
#define _MATERIAH_

#include <string>

class materia {
protected:
  int codigo;
  std::string nombre;
  std::string titular;

public:
  materia();
  materia(int x, std::string y, std::string z);

  void setCodigo(int x);
  void setNombre(std::string x);
  void setTitular(std::string x);

  int getCodigo();
  std::string getNombre();
  int getNota();
  std::string getTitular();

  void inscripcionEnMateria(int x, std::string y);
};

#endif // !_MATERIAH_
