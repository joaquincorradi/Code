#include <iostream>

struct cliente
{
  int nroCliente;
  int nroCajaPesos;
  float saldoPesos;
  int nroCajaDolares;
  float saldoDolares;
};

void menu(int &opcion);
void cargarDatosCliente(cliente datos[], int &cantidadClientes);
void cargarMovimientoPesos(cliente datos[], int cantidadClientes);
void cargarMovimientoDolares(cliente datos[], int cantidadClientes);
void mostrarSaldoCliente(cliente datos[], int cantidadClientes);
void iniciarOpciones(cliente datos[], int opcion, int cantidadClientes);

int main()
{
  int opcion;
  int cantidadClientes = 0;
  cliente datos[cantidadClientes];
  iniciarOpciones(datos, opcion, cantidadClientes);
}

void menu(int &opcion)
{
  std::cout << '\n';
  std::cout << " 1. Cargar Cliete" << '\n';
  std::cout << " 2. Cargar movimiento en caja de ahorros en pesos." << '\n';
  std::cout << " 3. Cargar movimiento en caja de ahorros en dolares." << '\n';
  std::cout << " 4. Mostrar saldo de cliente." << '\n';
  std::cout << " Elija una opcion: ";
  std::cin >> opcion;
}

void cargarDatosCliente(cliente datos[], int &cantidadClientes)
{
  std::cout << '\n';
  std::cout << "Ingrese el numero de cliente: ";
  std::cin >> datos[cantidadClientes].nroCliente;
  std::cout << "Ingrese el numero de caja de ahorro en pesos: ";
  std::cin >> datos[cantidadClientes].nroCajaPesos;
  std::cout << "Ingrese el numero de caja de ahorro en dolares: ";
  std::cin >> datos[cantidadClientes].nroCajaDolares;
  ++cantidadClientes;
}

void cargarMovimientoPesos(cliente datos[], int cantidadClientes)
{
  int guardarCliente = 0, monto = 0;
  char opcion;
  std::cout << '\n';
  std::cout << "Ingrese numero de cliente para realizar movimiento en pesos: ";
  std::cin >> guardarCliente;
  for (int i = 0; i <= cantidadClientes; ++i)
  {
    if (guardarCliente == datos[i].nroCliente)
    {
      std::cout << "Desea ingresar dinero o retirar pesos? (i/r): ";
      std::cin >> opcion;
      if (opcion == 'i')
      {
        std::cout << "Ingrese el monto en pesos que desea ingresar: ";
        std::cin >> monto;
        datos[i].saldoPesos += monto;
      }
      else
      {
        std::cout << "Ingrese el monto en pesos que desea retirar: ";
        std::cin >> monto;
        if (datos[i].saldoPesos < monto)
        {
          std::cout << "Saldo insuficiente";
        }
        else
        {
          datos[i].saldoPesos -= monto;
        }
      }
    }
  }
}

void cargarMovimientoDolares(cliente datos[], int cantidadClientes)
{
  int guardarCliente = 0, monto = 0;
  char opcion;
  std::cout << '\n';
  std::cout << "Ingrese numero de cliente para realizar movimiento en dolares: ";
  std::cin >> guardarCliente;
  for (int i = 0; i <= cantidadClientes; ++i)
  {
    if (guardarCliente == datos[i].nroCliente)
    {
      std::cout << "Desea ingresar dinero o retirar dolares? (i/r): ";
      std::cin >> opcion;
      if (opcion == 'i')
      {
        std::cout << "Ingrese el monto en dolares que desea ingresar: ";
        std::cin >> monto;
        datos[i].saldoDolares += monto;
      }
      else
      {
        std::cout << "Ingrese el monto en dolares que desea retirar: ";
        std::cin >> monto;
        if (datos[i].saldoDolares < monto)
        {
          std::cout << "Saldo insuficiente.";
        }
        else
        {
          datos[i].saldoDolares -= monto;
        }
      }
    }
    else
    {
      std::cout << "Cliente inexistente";
    }
  }
}

void mostrarSaldoCliente(cliente datos[], int cantidadClientes)
{
  char opcion;
  int guardarCliente = 0;
  std::cout << '\n';
  std::cout << "Desea visualizar saldo en dolares o pesos? (p/d): ";
  std::cin >> opcion;
  if (opcion == 'p')
  {
    std::cout << "Ingrese el numero de cliente: ";
    std::cin >> guardarCliente;
    for (int i = 0; i <= cantidadClientes; ++i)
    {
      if (datos[i].nroCliente == guardarCliente)
      {
        std::cout << "El saldo de la cuenta nro. " << guardarCliente << " es $" << datos[i].saldoPesos << '\n';
      }
    }
  }
  else
  {
    std::cout << "Ingrese el numero de cliente: ";
    std::cin >> guardarCliente;
    for (int i = 0; i <= cantidadClientes; ++i)
    {
      if (datos[i].nroCliente == guardarCliente)
      {
        std::cout << "El saldo de la cuenta nro. " << guardarCliente << " es $" << datos[i].saldoDolares;
      }
    }
  }
}

void iniciarOpciones(cliente datos[], int opcion, int cantidadClientes)
{
  char eleccion = 's';
  while (eleccion == 'S' || eleccion == 's')
  {
    menu(opcion);
    switch (opcion)
    {
    case 1: cargarDatosCliente(datos, cantidadClientes);
      break;

    case 2: cargarMovimientoPesos(datos, cantidadClientes);
      break;

    case 3: cargarMovimientoDolares(datos, cantidadClientes);
      break;
    
    case 4: mostrarSaldoCliente(datos, cantidadClientes);
      break;
  
    default: std::cout << "Opcion invalida.";
      break;
    }
    std::cout << "Desea realizar otra operacion? (s/n): ";
    std::cin >> eleccion;
  }
}