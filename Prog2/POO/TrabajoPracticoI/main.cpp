#include "src/alumno/alumno.h"
#include "src/docente/docente.h"
#include "src/estructura/estructura.h"
#include "src/materia/materia.h"

int main() {
  alumno *Alumno;
  Alumno = new alumno(0, "0", "0", "0", "0", 0);

  docente *Docente;
  Docente = new docente(0, "0", "0", "0", "0");

  materia *Materia[3];
  Materia[0] = new materia(847, "Analisis");
  Materia[1] = new materia(657, "Fisica");
  Materia[2] = new materia(374, "Programacion");

  estructura *Estructura;
  Estructura = new estructura();

  delete Alumno;
  delete Docente;
  delete Materia[0];
  delete Materia[1];
  delete Materia[2];
  delete Estructura;
}
