#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class libro {
private:
  std::string nombreDelLibro;
  std::string autorDelLibro;
  int anoDePublicacion;
  bool disponibilidadDelLibro;

public:
  libro();
  libro(std::string, std::string, int, bool);

  std::string getNombreDelLibro();
  std::string getAutorDelLibro();
  int getAnoDePublicacion();
  bool getDisponibilidadDelLibro();

  void setNombreDelLibro(std::string);
  void setAutorDelLibro(std::string);
  void setAnoDePublicacion(int);
  void setDisponibilidadDelLibro(bool);

  void iniciarPrestamo(bool);
};

#endif
