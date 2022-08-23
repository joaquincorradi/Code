#include <iostream>
#include <ctime> //time()
#include <cstdlib> //rand(), srand()

void juegoDados()
{ 
  bool continuarJuego = true;
  
  while (continuarJuego)
  {
    //Generación de los números:
    srand((unsigned) time(0)); //necesario para que el número varie cada vez que se ejecuta el programa
    int numAleatorio1 = (rand() % 6) + 1; //genera número aleatorio entre el 1 y el 6
    int numAleatorio2 = (rand() % 6) + 1;

    std::cout << "Le tocaron los numeros: " << numAleatorio1 << ", " << numAleatorio2 << std::endl;

    int sumaNumeros = numAleatorio1 + numAleatorio2;
    
    if (sumaNumeros == 7 || sumaNumeros == 11)
    {
      continuarJuego = false;
      std::cout << "Su puntaje es: " << sumaNumeros << "\n";
      std::cout << "Gano" << "\n"; 
      break;
    }
    else if (sumaNumeros == 2 || sumaNumeros == 3 || sumaNumeros == 12)
    {
      continuarJuego = false;
      std::cout << "Su puntaje es: " << sumaNumeros << "\n";
      std::cout << "Perdio" << std::endl;
      break;
    }
    else if (sumaNumeros == 4 || sumaNumeros == 5 || sumaNumeros == 6 || sumaNumeros == 8 ||
      sumaNumeros == 9 || sumaNumeros == 10)
    {
      continuarJuego = true;
      std::cout << "Su puntaje es: " << sumaNumeros << "\n";
      std::cout << "Se repite..." << "\n";
      std::cout << "\n";
    }
  }
}

int main()
{
  juegoDados();
  return 0;
}