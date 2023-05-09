#ifndef _CLASE2H_
#define _CLASE2H_

#include "../clase1/clase1.h"

class clase2 : public clase1 {
private:
  int x;
  char y;

public:
  clase2(int _n, float _m, int _x, char _y);

  int getX();
  char getY();

  void setX(int _x);
  void setY(char _y);

  int sumarNumeros2(int a);
  void agregarNumeros();
};

#endif
