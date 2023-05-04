#include "src/alumno/alumno.h"
#include "src/docente/docente.h"
#include "src/materia/materia.h"
#include <cstdlib>
#include <iostream>

int main() {
  alumno *Alumno;
  Alumno = new alumno(0, "0", "0", "0", "0", 0, 0.0);

  docente *Docente;
  Docente = new docente(0, "0", "0", "0", "0");

  materia *Materia[3];
  Materia[0] = new materia(847, "Analisis", "0");
  Materia[1] = new materia(657, "Fisica", "0");
  Materia[2] = new materia(374, "Programacion", "0");

  int contadorOpcion1Alumno = 0;
  int *pContadorOpcion1Alumno = &contadorOpcion1Alumno;
  int contadorOpcion1Docente = 0;
  int *pContadorOpcion1Docente = &contadorOpcion1Docente;
  int seleccionDelUsuario;
  int *pSeleccionDelUsuario = &seleccionDelUsuario;
  char seleccionFinalMenu = 'S';
  char *pSeleccionFinalMenu = &seleccionFinalMenu;
  bool caso6 = false;
  bool *pCaso6 = &caso6;
  float notaAlumno;
  float *pNotaAlumno = &notaAlumno;
  char seleccionOpcion1;
  char *pSeleccionOpcion1 = &seleccionOpcion1;
  int seleccionOpcion2;
  int *pSeleccionOpcion2 = &seleccionOpcion2;
  int seleccionOpcion3;
  int *pSeleccionOpcion3 = &seleccionOpcion3;
  int seleccionOpcion4;
  int *pSeleccionOpcion4 = &seleccionOpcion4;
  char seleccionOpcion5;
  char *pSeleccionOpcion5 = &seleccionOpcion5;

  while (*pSeleccionFinalMenu == 'S' || *pSeleccionFinalMenu == 's') {
    std::cout << "MENU PRINCIPAL\n";
    std::cout << "[1] Darse de alta.\n";
    std::cout << "[2] Incribirse a materia.\n";
    std::cout << "[3] Anotar titular de materia.\n";
    std::cout << "[4] Cargar notas.\n";
    std::cout << "[5] Modificar datos.\n";
    std::cout << "[6] Salir.\n";
    std::cout << "Elija una opcion: ";
    std::cin >> *pSeleccionDelUsuario;
    std::cout << std::flush;
    system("cls||clear");

    switch (*pSeleccionDelUsuario) {
    case 1:
      std::cout << "Desea dar de alta a un alumno [a] o a un docente [d]?: ";
      std::cin >> *pSeleccionOpcion1;
      if (*pSeleccionOpcion1 == 'a' || *pSeleccionOpcion1 == 'A') {
        if (*pContadorOpcion1Alumno == 0) {
          ++*pContadorOpcion1Alumno;
          Alumno->modificarDatosAlumno();
        } else {
          std::cout << "Solo se puede ingresar un alumno en el sistema.";
        }
      } else {
        if (*pContadorOpcion1Docente == 0) {
          ++*pContadorOpcion1Docente;
          Docente->modificarDatosDocente();
        } else {
          std::cout << "Solo se puede ingresar un docente en el sistema.";
        }
      }
      break;

    case 2:
      std::cout << "Materias disponibles: \n";
      for (int i = 0; i < 3; ++i) {
        std::cout << "[" << i << "] " << Materia[i]->getNombre() << '\n';
      }
      std::cout << "Seleccione una opcion: ";
      std::cin >> *pSeleccionOpcion2;
      break;

    case 3:
      std::cout << "Materias disponibles: \n";
      for (int i = 0; i < 3; ++i) {
        std::cout << "[" << i << "] " << Materia[i]->getNombre() << '\n';
      }
      std::cout << "Seleccione una opcion: ";
      std::cin >> *pSeleccionOpcion3;
      Materia[*pSeleccionOpcion3]->setTitular(Docente->getApellido());
      std::cout << "Ahora el titular de "
                << Materia[*pSeleccionOpcion3]->getNombre() << " es "
                << Materia[*pSeleccionOpcion3]->getTitular() << '\n';
      break;
    case 4:
      std::cout << "Cargar nota a " << Alumno->getNombre() << " "
                << Alumno->getApellido() << '\n';
      std::cout << "La nota es: ";
      std::cin >> *pNotaAlumno;
      Alumno->setNota(*pNotaAlumno);
      std::cout << "El alumno " << Alumno->getNombre() << " "
                << Alumno->getApellido() << " tiene " << Alumno->getNota()
                << '\n';
      break;
    case 5:
      std::cout
          << "Desea modificar los datos de un alumno [a] o a un docente [d]?: ";
      std::cin >> *pSeleccionOpcion5;
      if (*pSeleccionOpcion5 == 'a' || *pSeleccionOpcion5 == 'A') {
        std::cout << "Se modificaran los datos del alumno: "
                  << Alumno->getNombre() << " " << Alumno->getApellido()
                  << '\n';
        Alumno->modificarDatosAlumno();
      } else {
        std::cout << "Se modificaran los datos del docente :"
                  << Docente->getNombre() << " " << Docente->getApellido()
                  << '\n';
        Docente->modificarDatosDocente();
      }
      break;
    case 6:
      *pCaso6 = true;
      break;

    default:
      std::cout << "Opcion invalida\n";

      break;
    }
    if (!caso6) {
      std::cout << "¿Desea volver al menu principal? [S/n]: ";
      std::cin >> *pSeleccionFinalMenu;
      if (*pSeleccionFinalMenu == 's' || *pSeleccionFinalMenu == 'S') {
        system("cls||clear");
      }
    } else {
      *pSeleccionFinalMenu = 'n';
    }
  }

  delete Alumno;
  delete Docente;
  delete Materia[0];
  delete Materia[1];
  delete Materia[2];
}
