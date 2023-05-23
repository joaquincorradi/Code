#include <iostream>
#include <string>

class Cliente {
  std::string nombre;
  std::string apellido;

public:
  Cliente(std::string _nombre, std::string _apellido)
      : nombre(_nombre), apellido(_apellido) {}
  void operator++(int) { std::cout << "Hola"; }
};

int main() {
  Cliente cliente("", "");
  cliente++;
  return 0;
}
