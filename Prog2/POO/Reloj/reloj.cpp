#include "../Reloj/reloj.h"

reloj::reloj(int hr, int min, int seg) { h = hr, m = min, s = seg; }
void reloj::setHora(int hr) { h = hr; }
void reloj::setMinuto(int min) { m = min; }
void reloj::setSegundo(int seg) { s = seg; }
int reloj::getHora() { return h; }
int reloj::getMinuto() { return m; }
int reloj::getSegundo() { return s; }
void reloj::operator++() {
  ++s;
  if (s == 60) {
    ++m;
    s = 0;
  }
  if (m == 60) {
    ++h;
    m = 0;
  }
}
