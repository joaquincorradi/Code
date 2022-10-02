#include <iostream>

void cantidadVuelos(int &vuelos)
{
  std::cout << '\n';
  std::cout << "Ingrese la cantidad de vuelos del dia: ";
  std::cin >> vuelos;
}

void ingresarNumeroVuelo(int vuelos, int numero[])
{
  std::cout << '\n';
  std::cout << "Ingrese el numero de lo: ";
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    std::cin >> numero[i];
  }
}

void ingrearCantPasajeros(int vuelos, int pasajeros[], int numero[])
{
  std::cout << '\n';
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    std::cout << "Ingrese la cantidad de pasajeros del vuelo nro. " << numero[i] << ": ";
    std::cin >> pasajeros[i];
  }
}

void ingresarEstado(int vuelos, int estado[], int numero[])
{
  std::cout << '\n';
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    std::cout << "Ingrese el estado del vuelo nro. " << numero[i] << ": ";
    std::cin >> estado[i];
  }
}

int calcRetrasados(int vuelos, int estado[])
{
  int retrasados;
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    if (estado[i] == 0)
    {
      ++retrasados;
    }
  }
  return retrasados;
}

int calcPorcentaje(int vuelos, int retrasados)
{
  return (retrasados * 100) / vuelos;
}

int calcMayor(int vuelos, int pasajeros[])
{
  int mayor;
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    if (pasajeros[i] > mayor)
    {
      mayor = pasajeros[i];
    }
  }
  return mayor;
}

int calcPromedio(int vuelos, int pasjeros[])
{
  int promedio;
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    
  }
}

int main()
{
  int vuelos;
  cantidadVuelos(vuelos);
  int numero[vuelos];
  ingresarNumeroVuelo(vuelos, numero);
  int pasajeros[vuelos];
  ingrearCantPasajeros(vuelos, pasajeros, numero);
  int estado[vuelos];
  ingresarEstado(vuelos, estado, numero);
  int retrasados = calcRetrasados(vuelos, estado);
  int porcentaje = calcPorcentaje(vuelos, retrasados);
  int mayor = calcMayor(vuelos, pasajeros);
}