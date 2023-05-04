#ifndef _PERSONAH_
#define _PERSONAH_

#include <string>

class persona {
private:
  int dni;
  std::string nombre;
  std::string apellido;
  std::string mail;

public:
  persona(int x, std::string y, std::string z, std::string w);

  void setDni(int x);
  void setNombre(std::string x);
  void setApellido(std::string x);
  void setMail(std::string x);

  int getDni();
  std::string getNombre();
  std::string getApellido();
  std::string getMail();

  void modificarDatos();
  void consultarDatos();
};

#endif // !_PERSONAH_
