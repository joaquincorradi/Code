#include <iostream>

void ingresarPreguntas(int preguntas[10])
{
  std::cout << '\n';
  std::cout << "Ingrese las respuestas a las preguntas: ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cin >> preguntas[i];
  }
}

void ingresarRespuestas(int respuestas[10])
{
  std::cout << '\n';
  std::cout << "Ingrese las respuestas del alumno: ";
  for (int i = 0; i <= 9; ++i)
  {
    std::cin >> respuestas[i];
  }
}

int calcPuntaje(int preguntas[10], int respuestas[10])
{
  int puntaje = 0;
  for (int i = 0; i <= 9; ++i)
  {
    if (respuestas[i] == preguntas[i])
    {
      puntaje += 5;
    }
  }
  return puntaje; 
}

int calcCorrectas(int preguntas[10], int respuestas[10])
{
  int correctas = 0;
  for (int i = 0; i <= 9; ++i)
  {
    if (respuestas[i] == preguntas[i])
    {
      ++correctas;
    }
  }
  return correctas;
}

int calcIncorrectas(int preguntas[10], int respuestas[10])
{
  int incorrectas = 0;
  for (int i = 0; i <= 9; ++i)
  {
    if (respuestas[i] != preguntas[i])
    {
      ++incorrectas;
    }
  }
  return incorrectas;
}

void mostrarResultados(int puntaje, int correctas, int incorrectas)
{
  std::cout << '\n';
  std::cout << "El puntaje obtenido es: " << puntaje << '\n';
  std::cout << "La cantidad de respuestas correctas es: " << correctas << '\n';
  std::cout << "La cantidad de respuestas incorrectas es: " << incorrectas << '\n';
  std::cout << '\n';
}

int main()
{
  int preguntas[10];
  ingresarPreguntas(preguntas);
  int respuestas[10];
  ingresarRespuestas(respuestas);
  int puntaje = calcPuntaje(preguntas, respuestas);
  int correctas = calcCorrectas(preguntas, respuestas);
  int incorrectas = calcIncorrectas(preguntas, respuestas);
  mostrarResultados(puntaje, correctas, incorrectas);
}