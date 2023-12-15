#include <stdio.h>
#include <stdlib.h>
#include "./parse.h"

void init_pilha(Pilha *p, int size)
{
  p->str = (char *)malloc(size * sizeof(char));
  p->size = size;
  p->top = -1;
}

void push(Pilha *p, char c)
{
  if (p->top < p->size - 1)
  {
    p->str[++p->top] = c;
  }
  else
  {
    printf("Pilha cheia!\n");
  }
}

void pop(Pilha *p)
{
  if (p->top >= 0)
  {
    p->top--;
  }
  else
  {
    printf("Pilha vazia!\n");
  }
}

void processar_linha(Pilha *p, char *linha)
{
  int max = 0;
  for (int i = 0; linha[i] != '\0'; i++)
  {
    max++;
    if (linha[i] == '#')
    {
      pop(p);
    }
    else
    {
      push(p, linha[i]);
    }
  }
  if (max > 0 && max < p->size - 1)
  {
    mostrar_pilha(p);
  }
  else
  {
    printf("A linha nao pode possuir mais de %d caracteres.", p->size);
  }
}

void mostrar_pilha(Pilha *p)
{
  for (int i = 0; i <= p->top; i++)
  {
    printf("%c", p->str[i]);
  }
  printf("\n");
}

void free_pilha(Pilha *p)
{
  free(p->str);
  p->str = NULL;
  p->size = 0;
  p->top = -1;
}