#include "./fecha.h"

fecha::fecha(int _dia, int _mes, int _ano) {
  dia = _dia;
  mes = _mes;
  ano = _ano;
}

int fecha::getDia() { return dia; }
int fecha::getMes() { return mes; }
int fecha::getAno() { return ano; }

void fecha::setDia(int _dia) { dia = _dia; }
void fecha::setMes(int _mes) { mes = _mes; }
void fecha::setAno(int _ano) { ano = _ano; }

void fecha::operator++() { ++dia; }
void fecha::operator--() { --dia; }
void fecha::operator-(int a) { dia += a; }
void fecha::operator+(int a) { dia -= a; }
