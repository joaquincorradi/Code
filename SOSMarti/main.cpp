#include <fstream>
#include <iostream>

struct persona {
  int edad;
  char sexo;
  int ingresos;
  int region;
};

void menu();
void guardarDatos(persona datos[10]);
void leerDatos();
int mediaIngresos();
void sexoPorRegion();

int main() {}

void menu() {
  // escribir menu aca
}

void guardarDatos(persona datos[10]) {
  std::ofstream datosCensado("datos.txt");
  int temp1, temp2, temp4;
  char temp3;
  for (int i = 0; i < 10; ++i) {
    std::cout << "Ingrese a continuacion el dato de la persona nro. " << i + 1
              << '\n';
    std::cout << "Edad: ";
    std::cin >> temp1;
    datosCensado << temp1;
  }
}
