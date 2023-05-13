#ifndef BANCO_H
#define BANCO_H

#include <string>

class banco {
private:
  std::string nombreDelBanco;

public:
  banco(std::string);

  std::string getNombreDelBanco();

  void setNombreDelBanco(std::string);
};

#endif
