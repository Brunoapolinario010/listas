#include <stdio.h>
#include "modulos/caixa.h"

int main(int argc, char *argv[])
{
  int cedulas[] = {200, 100, 50, 20, 10, 5, 2};
  int tam = 7;

  int valor;
  scanf("%d", &valor);
  realizarSaque(valor, cedulas, tam);

  return 0;
}