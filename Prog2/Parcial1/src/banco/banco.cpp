#include "./banco.h"
#include <string>

banco::banco(std::string _nombreDelBanco) { nombreDelBanco = _nombreDelBanco; }

std::string banco::getNombreDelBanco() { return nombreDelBanco; }

void banco::setNombreDelBanco(std::string _nombreDelBanco) {
  nombreDelBanco = _nombreDelBanco;
}
