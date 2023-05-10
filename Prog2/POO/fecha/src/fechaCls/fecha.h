#ifndef FECHA_H
#define FECHA_H

class fecha {
private:
  int dia, mes, ano;

public:
  fecha(int, int, int);

  int getDia();
  int getMes();
  int getAno();

  void setDia(int);
  void setMes(int);
  void setAno(int);

  void operator++();
  void operator--();
  void operator-(int);
  void operator+(int);
};

#endif
