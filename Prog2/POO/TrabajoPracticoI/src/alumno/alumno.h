#include "../materia/materia.h"
#include "../persona/persona.h"
#include <string>

class alumno : public persona {
private:
  std::string carrera;
  int edad;
  materia Materia;

public:
  void inscripcionEnMateria();
  void cargaDeNota();
};
