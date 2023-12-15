#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

#define N 5

struct _fila {
    int ini, fim;
    int elems[N];
};

Fila *cria() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->ini = 0;
        f->fim = 0;
   }
   return f;
}

int filaEstaVazia(Fila *f) {
    return f->ini == f->fim;
}

void liberarFila(Fila *f) {
    free(f);
}

// incremento circular
int incr(int i) {
    return (i + 1) % N;
}

void imprimirFila(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("Fila vazia!!\n");
        return;
    }
    printf("Elementos na fila:\n");
    printf("ini: %d\n", f->ini);
    printf("fim: %d\n", f->fim);
    for (int i = f->ini; i != f->fim; i = incr(i)) {
        printf("%d <- ", f->elems[i]);        
    }
    printf("\n\n");
}
// enfileirar
void enqueue(Fila *f, int elem) {
    if (incr(f->fim) == f->ini) {
        printf("fila cheia - queue overflow!!!\n");
        return;
    }
    
    f->elems[f->fim] = elem;
    f->fim = incr(f->fim);    
}

int dequeue(Fila *f) {
    int ret = -1;
    if (filaEstaVazia(f)) {
        printf("Fila vazia - queue underflow!!!\n");
        return -1;
    }
    
    ret = f->elems[f->ini];
    f->elems[f->ini] = -1;
    f->ini = incr(f->ini);   
    return ret;
}
