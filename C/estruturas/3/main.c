#include <stdio.h>
#include "./modulos/parse.h"

int main(int argc, char *argv[])
{
  char linha[MAX];
  fgets(linha, MAX, stdin);

  Pilha p;
  init_pilha(&p, MAX);
  processar_linha(&p, linha);

  free_pilha(&p);
  return 0;
}
