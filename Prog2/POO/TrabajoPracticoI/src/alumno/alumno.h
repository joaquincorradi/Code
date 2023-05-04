#include "../materia/materia.h"
#include "../persona/persona.h"
#include <string>

class alumno : public persona {
private:
  std::string carrera;
  int edad;
  float nota;

public:
  materia Materia;
  alumno(int x, std::string y, std::string z, std::string w, std::string u,
         int v, float j);

  void setNota(int x);
  float getNota();

  void modificarDatosAlumno();
};
