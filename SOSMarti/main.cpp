#include <fstream>
#include <iostream>

struct persona {
  int edad;
  char genero;
  int ingresos;
  int region;
};

void menu();
void guardarDatos(persona datos[10]);
void leerDatos();
int mediaIngresos();
void generoPorRegion();

int main() {}

void menu() {
  // escribir menu aca
}

void guardarDatos(persona datos[10]) {
  std::ofstream datosCensado("datos.txt");
  int temp1, temp3, temp4;
  char temp2;
  for (int i = 0; i < 10; ++i) {
    std::cout << "Ingrese a continuacion el dato de la persona nro. " << i + 1
              << '\n';
    std::cout << "Edad: ";
    std::cin >> temp1;
    datosCensado << temp1;
    std::cout << "Genero [M-F]: ";
    std::cin >> temp2;
    datosCensado << temp2;
    std::cout << "Ingresos: ";
    std::cin >> temp3;
    datosCensado << temp3;
    std::cout << "Region [1-3]: ";
    std::cin >> temp4;
    datosCensado << temp4 << '\n';
  }
}

void leerDatos(persona datos[10]) {
  // ...
}
