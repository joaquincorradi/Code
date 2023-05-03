#include <string>

class materia {
protected:
  int codigo;
  std::string nombre;
  int nota;

public:
  materia();
  materia(int x, std::string y, int z);

  void setCodigo(int x);
  void setNombre(std::string x);
  void setNota(int x);

  int getCodigo();
  std::string getNombre();
  int getNota();
};
