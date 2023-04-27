#include "../../persona.h"
#include <string>

class alumno : public persona {
  std::string carrera;
  int edad;

public:
  void inscripcionEnMateria();
  void cargaDeNota();
};
