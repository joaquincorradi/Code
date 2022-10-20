#include <iostream>

struct produccion
{
  int lote, maquina, cantPiezas, cantPiezasFalladas;
};

void menu();
void cargarProduccion(produccion datos[], int dias);
void calcMedia(produccion datos[], int dias);
void calcMediaFallados(produccion datos[], int dias);
void calcPiezasProducidas(produccion datos[], int dias);
void calcPorcentaje(produccion datos[], int dias);

int main()
{
  int opcion, dias = 0;
  produccion datos[dias];
}

void menu(int &opcion)
{
  std::cout << '\n';
  std::cout << "\tBIENVENIDO" << '\n';
  std::cout << '\n';
  std::cout << "1. Ingresar datos de produccion." << '\n';
  std::cout << "2. Calcular media de produccion." << '\n';
  std::cout << "3. Calcular media de piezas falladas." << '\n';
  std::cout << "4. Total de piezas producidad." << '\n';
  std::cout << "5. Calcular porcentaje de piezas correctas y falladas." << '\n';
  std::cout << '\n';
  std::cout << "Ingrese una opcion: ";
  std::cin >> opcion;
}

void cargarProduccion(produccion datos[], int &dias)
{
  std::cout << '\n';
  std::cout << "Ingrese lote de produccion: ";
  std::cin >> datos[dias].lote;
  std::cout << "Ingrese numero de maquina: ";
  std::cin >> datos[dias].maquina;
  std::cout << "Ingrese la cantidad total de piezas: ";
  std::cin >> datos[dias].cantPiezas;
  std::cout << "Ingrese la cantidad de piezas falladas: ";
  std::cin >> datos[dias].cantPiezasFalladas;
  ++dias;
}

void calcMedia(produccion datos[], int dias)
{
  int suma;
  for (int i = 0; i <= dias - 1; ++i)
  {
    suma += datos[i].cantPiezas;
  }
  std::cout << '\n';
  std::cout << "La media de produccion en " << dias << " dias es: " << suma << " unidades." << '\n';
}

void calcMediaFallados(produccion datos[], int dias)
{
  int suma;
  for (int i = 0; i <= dias - 1; ++i)
  {
    suma += datos[i].cantPiezasFalladas;
  }
  std::cout << '\n';
  std::cout << "La media fallada de produccion en " << dias << " dias es: " << suma << " unidades." << '\n';
}

void calcPiezasProducidas(produccion datos[], int dias)
{
  int suma;
  for (int i = 0; i <= dias - 1; ++i)
  {
    suma += datos[i].cantPiezas;
  }
  std::cout << '\n';
  std::cout << "El total producido en " << dias << " dias es " << suma << " unidades." << '\n';
}