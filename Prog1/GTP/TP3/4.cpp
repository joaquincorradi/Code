#include <iostream>

void ingresarNombre(std::string nombres[8])
{
  std::cout << '\n';
  std::cout << "Ingrese los nombres de los pacientes: ";
  for (int i = 0; i <= 7; ++i)
  {
    std::cin >> nombres[i];
  }
}

void ingresarEdad(int edades[8], std::string nombres[8])
{
  std::cout << '\n';
  for (int i = 0; i <= 7; ++i)
  {
    std::cout << "Ingrese la edad de " << nombres[i] << ": ";
    std::cin >> edades[i];
  }
}

void ingresarCantVisitas(int visitas[8], std::string nombres[8])
{
  std::cout << '\n';
  for (int i = 0; i <= 7; ++i)
  {
    std::cout << "Ingrese la cantidad de visitas previas de " << nombres[i] << ": ";
    std::cin >> visitas[i];
  }
}

int calcMasVisPrevias(int visitas[8])
{
  int contador = 0;
  for (int i = 0; i <= 7; ++i)
  {
    if (visitas[i] > 4)
    {
      ++contador;
    }
  }
  return contador;
}

void masLongevo(std::string nombres[8], int edades[8], std::string nombreLongevo[3], int edadLongevo[3])
{
  for (int i = 0; i <= 7; ++i)
  {
    if (edades[i] > edadLongevo[0])
    {
      edadLongevo[2] = edadLongevo[1];
      edadLongevo[1] = edadLongevo[0];
      edadLongevo[0] = edades[i];
    
      nombreLongevo[2] = nombreLongevo[1];
      nombreLongevo[1] = nombreLongevo[0];
      nombreLongevo[0] = nombres[i];
    }
    else if (edades[i] > edadLongevo[1])
    {
      edadLongevo[2] = edadLongevo[1];
      edadLongevo[1] = edades[i];

      nombreLongevo[2] = nombreLongevo[1];
      nombreLongevo[1] = nombres[i];
    }
    else if (edades[i] > edadLongevo[2])
    {
      edadLongevo[2] = edades[i];

      nombreLongevo[2] = nombres[i];
    }
  }
}

void masJoven(std::string nombres[8], int edades[8], std::string &nombreJoven)
{
  int guardar = edades[0];
  for (int i = 0; i <= 7; ++i)
  {
    if (edades[i] < guardar)
    {
      guardar = edades[i];
      nombreJoven = nombres[i];
    }
  }
}

void mostrarResultados(int visPrevias, std::string nombreLongevo[3], int edadLongevo[3], std::string nombreJoven)
{
  std::cout << '\n';
  std::cout << "La cantidad de pacientes con mas de 4 visitas previas son: " << visPrevias << '\n';
  std::cout << "Los tres pacientes mas longevos son: " << '\n';
  for (int i = 0; i <= 2; ++i)
  {
    std::cout << nombreLongevo[i] << " que tiene " << edadLongevo[i] << " anos."  << '\n';
  }
  std::cout << "El paciente mas joven es: " << nombreJoven  << '\n';
}

int main()
{
  std::string nombres[8];
  ingresarNombre(nombres);
  int edades[8];
  ingresarEdad(edades, nombres);
  int visitas[8];
  ingresarCantVisitas(visitas, nombres);
  int visPrevias = calcMasVisPrevias(visitas);
  std::string nombreLongevo[3];
  int edadLongevo[3];
  masLongevo(nombres, edades, nombreLongevo, edadLongevo);
  std::string nombreJoven;
  masJoven(nombres, edades, nombreJoven);
  mostrarResultados(visPrevias, nombreLongevo, edadLongevo, nombreJoven);
}