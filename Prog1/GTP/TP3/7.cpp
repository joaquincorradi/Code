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
  std::cout << "Ingrese el numero de cada vuelo: ";
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
  int retrasados = 0;
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

int calcMayor(int vuelos, int pasajeros[], int numero[])
{
  int guardar = 0, mayor = 0;
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    if (pasajeros[i] > guardar)
    {
      guardar = pasajeros[i];
      mayor = numero[i];
    }
  }
  return mayor;
}

int calcPromedio(int vuelos, int pasajeros[])
{
  int promedio = 0;
  for (int i = 0; i <= vuelos - 1; ++i)
  {
    promedio += pasajeros[i];
  }
  return promedio / vuelos;
}

void mostrarResultados(int retrasados, int porcentaje, int mayor, int promedio)
{
  std::cout << '\n';
  std::cout << "La cantidad de vuelos retrasados es de " << retrasados << " que es el " << porcentaje << "% de los vuelos totales" << '\n';
  std::cout << "El vuelo con mayor numero de pasajeros es el nro. " << mayor << '\n';
  std::cout << "El numero promedio de pasajeros es " << promedio << '\n';
  std::cout << '\n';
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
  int mayor = calcMayor(vuelos, pasajeros, numero);
  int promedio = calcPromedio(vuelos, pasajeros);
  mostrarResultados(retrasados, porcentaje, mayor, promedio);
}