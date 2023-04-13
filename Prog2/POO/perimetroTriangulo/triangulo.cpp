#include "../perimetroTriangulo/triangulo.h"

triangulo::triangulo(int x, int y, int z) { l1 = x, l2 = y, l3 = z; }
void triangulo::setl1(int x) { l1 = x; }
void triangulo::setl2(int y) { l2 = y; }
void triangulo::setl3(int z) { l3 = z; }
int triangulo::getl1() { return l1; }
int triangulo::getl2() { return l2; }
int triangulo::getl3() { return l3; }
int triangulo::getp() { return p; }
void triangulo::perimetro() { p = l1 + l2 + l3; }
