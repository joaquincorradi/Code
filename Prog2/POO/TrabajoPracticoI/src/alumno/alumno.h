#include "../persona/persona.h"
#include <string>

class alumno : public persona {
private:
  std::string carrera;
  int edad;

public:
  void inscripcionEnMateria();
  void cargaDeNota();
};
