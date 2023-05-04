#include "../materia/materia.h"
#include "../persona/persona.h"
#include <string>

class alumno : public persona {
private:
  std::string carrera;
  int edad;
  materia Materia;

public:
  alumno(int x, std::string y, std::string z, std::string w, std::string u,
         int v);
  void inscripcionEnMateria();
};
