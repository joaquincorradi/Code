#include <iostream>
#include <string>

int main() {
  std::string cadena = "joaquin", *p;
  p = &cadena;

  *p = toupper(*p);
}
