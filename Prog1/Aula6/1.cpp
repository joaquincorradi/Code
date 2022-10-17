#include <iostream>

struct cliente
{
  int nroCajaPesos;
  float saldoPesos;
  int nroCajaDolares;
  float saldoDolares;
  int nroCliente;
};

void menu(int &opcion)
{
  std::cout << '\n';
  std::cout << " 1. Cargar Cliete";
  std::cout << " 2. Cargar movimiento en caja de ahorros en pesos." << '\n';
  std::cout << " 3. Cargar movimiento en caja de ahorros en dolares." << '\n';
  std::cout << " 4. Mostrar saldo de cliente." << '\n';
  std::cout << " Elija una opcion: " << '\n';
  std::cin >> opcion;
}

void cargarDatos()
{
  
}

void checkOpcion(int opcion, int &cantidadClientes)
{
  char continuar = 's';
  while (continuar == 's' || continuar == 'S')
  {
    switch (opcion)
    {
    case 1:
      break;

    case 2:
      break;

    case 3:
      break;
    
    case 4:
      break;

    default:
      break;
    }
    std::cout << "Desea continuar? (s/N)";
    std::cin >> continuar;
    ++cantidadClientes;
  }
}

int main()
{
  int opcion;
  menu(opcion);
  int cantidadClientes;
}