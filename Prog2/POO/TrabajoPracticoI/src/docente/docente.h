#include "../materia/materia.h"
#include "../persona/persona.h"
#include <string>

class docente : public persona {
private:
  std::string titulo;
  materia Materia;

public:
  docente(int x, std::string y, std::string z, std::string w, std::string u);
  void asignarMateria();
};
