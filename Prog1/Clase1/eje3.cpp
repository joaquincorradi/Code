#include <iostream>

int respCorrect(int corr, int incorr, int blanco)
{
  int puntCorr = corr * 4;
  int puntIncorr = incorr * -1;

  return puntCorr + puntIncorr;
}

int main()
{
  int corr, incorr, blanco;
  
  std::cin >> corr >> incorr >> blanco;
  std::cout << respCorrect(corr, incorr, blanco);
}