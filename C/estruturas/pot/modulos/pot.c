#include <stdio.h>
#include "./pot.h"

float pot(float x, int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 1 / pot(x, -n);
  return x * pot(x, n - 1);
}