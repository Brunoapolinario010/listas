#include <stdio.h>
#include <stdlib.h>
#include "./modulos/pessoa.h"

int main()
{
  int qtdPessoas;
  printf("Digite a quantidade de pessoas: ");
  scanf("%d", &qtdPessoas);

  Pessoa *pessoas = (Pessoa *)malloc(qtdPessoas * sizeof(Pessoa));
  if (pessoas == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  for (int i = 0; i < qtdPessoas; i++)
  {
    lerDados(&pessoas[i]);
    calcularIdade(&pessoas[i]);
  }

  for (int i = 0; i < qtdPessoas; i++)
  {
    mostrarDados(&pessoas[i]);
  }

  free(pessoas);

  return 0;
}