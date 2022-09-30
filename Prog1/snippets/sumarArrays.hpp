#include <iostream>

void sumarArrays(int n, int array1[], int array2[], int arraySuma[])
{
  for (int i = 0; i <= n - 1; ++i)
  {
    arraySuma[i] = array1[i] + array2[i];
  }
}