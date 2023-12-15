#ifndef _PARSE_H
#define _PARSE_H

#define MAX 100

typedef struct _pilha
{
  int top;
  int size;
  char *str;
} Pilha;

void init_pilha(Pilha *p, int size);

void push(Pilha *p, char c);

void pop(Pilha *p);

void processar_linha(Pilha *p, char *linha);

void mostrar_pilha(Pilha *p);

void free_pilha(Pilha *p);

#endif