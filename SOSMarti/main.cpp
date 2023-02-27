#include <fstream>
#include <iostream>

struct persona {
  int edad;
  char genero;
  int ingresos;
  int region;
};

void menu(int opcion);
void guardarDatos();
void leerDatos(persona datos[10]);
void mediaIngresos(persona datos[10]);
void generoPorRegion();

int main() { guardarDatos(); }

void menu(int opcion) {
  std::cout << "Elija un opcion\n";
  std::cout << "1 ...\n";
  std::cout << "2 ...\n";
  std::cin >> opcion;
}

void guardarDatos() {
  std::ofstream datosCensado("datos.txt");
  int temp1, temp3, temp4;
  char temp2;
  for (int i = 0; i < 10; ++i) {
    std::cout << "Ingrese a continuacion el dato de la persona nro. " << i + 1
              << '\n';
    std::cout << "Edad: ";
    std::cin >> temp1;
    datosCensado << temp1 << '\t';

    std::cout << "Genero [M-F]: ";
    std::cin >> temp2;
    datosCensado << temp2 << '\t';

    std::cout << "Ingresos: ";
    std::cin >> temp3;
    datosCensado << temp3 << "\t";

    std::cout << "Region [1-3]: ";
    std::cin >> temp4;
    datosCensado << temp4 << '\n';
  }
  datosCensado.close();
}

void leerDatos(persona datos[10]) {
  std::ifstream datosCensado("datos.txt");
  for (int i = 0; i < 10; ++i) {
    datosCensado >> datos[i].edad;
    datosCensado >> datos[i].genero;
    datosCensado >> datos[i].ingresos;
    datosCensado >> datos[i].region;
  }
}

void mediaIngresos(persona datos[10]) {
  int suma = 0;
  int resultado = 0;
  for (int i = 0; i < 10; ++i) {
    suma += datos[i].ingresos;
  }
  resultado = suma / 10;
  std::cout << "El ingreso promedio es " << resultado << '\n';
}
