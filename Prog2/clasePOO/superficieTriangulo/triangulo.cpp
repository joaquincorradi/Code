#include "../superficieTriangulo/triangulo.h"

triangulo::triangulo(int x, int y) { b = x, h = y; }
void triangulo::setb(int base) { b = base; }
void triangulo::seth(int altura) { h = altura; }
int triangulo::getb() { return b; }
int triangulo::geth() { return h; }
int triangulo::gets() { return s; }
void triangulo::superficie() { s = (b * h) / 2; }
