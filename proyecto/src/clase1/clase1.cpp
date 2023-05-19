#include "./clase1.h"
#include <iostream>

clase1::clase1(int _n, float _m) : n(_n), m(_m) {}

int clase1::getN() { return n; }
float clase1::getM() { return m; }

void clase1::setN(int _n) { n = _n; }
void clase1::setM(float _m) { m = _m; }

void clase1::sumarNumeros() { std::cout << "n + m = " << n + m << '\n'; }
void clase1::imprimirClase1() { std::cout << "Soy la clase 1\n"; }
