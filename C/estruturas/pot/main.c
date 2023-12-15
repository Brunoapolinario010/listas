#include <stdio.h>
#include "./modulos/pot.h"

int main(int argc, char *argv[])
{
  printf("%.4f\n", pot(2, -3));
  printf("%.4f\n", pot(2, 3));
  return 0;
}