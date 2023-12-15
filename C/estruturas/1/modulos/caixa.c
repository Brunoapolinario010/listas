#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"

void realizarSaque(int valor, int *cedulas, int tam)
{
  if (valor <= 0)
  {
    printf("Informe um valor maior que 0\n");
    return;
  }

  int *quantidadeCedulas = malloc(tam * sizeof(int));

  if (!quantidadeCedulas)
  {
    printf("Erro ao alocar memoria\n");
    return;
  }

  for (int i = 0; i < tam; i++)
  {
    quantidadeCedulas[i] = 0;
  }

  for (int i = 0; i < tam; i++)
  {
    for (int j = 0; j < tam; j++)
    {
      if (valor - cedulas[i] == 0 ||
          ((valor - cedulas[i]) % 2 == 0 && valor - cedulas[i] > 0) ||
          ((valor - cedulas[i]) % 2 == 1 && valor - cedulas[i] > cedulas[j - 1]) ||
          (valor - cedulas[i] >= cedulas[j - 1] && (valor - cedulas[i]) % 2 == 0 && valor - cedulas[i] > 0))
      {
        quantidadeCedulas[i]++;
        valor -= cedulas[i];
        if (valor == 0)
        {
          break;
        }
      }
    }
  }

  if (valor > 0)
  {
    printf("Nao e possivel sacar o valor solicitado\n");
    return;
  }

  for (int i = 0; i < tam; i++)
  {
    printf("%d cedula(s) de %.2f\n", quantidadeCedulas[i], (float)cedulas[i]);
  }

  free(quantidadeCedulas);
}