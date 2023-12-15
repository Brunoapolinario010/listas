#ifndef _FILA_H
#define _FILA_H

typedef struct _fila Fila;

// Operações do TAD fila
Fila *cria();
void enqueue(Fila *f, int elem); // enfileirar
int dequeue(Fila *f); // desenfileirar
int filaEstaVazia(Fila *f);
void liberarFila(Fila *f);
void imprimirFila(Fila *f);
int incr(int i);

#endif

