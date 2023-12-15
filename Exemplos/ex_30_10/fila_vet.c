#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct _fila Fila;

struct _fila
{
    int ini, fim;
    int elems[N];
};

// Operações do TAD fila
Fila *cria();
void enqueue(Fila *f, int elem); // enfileirar
int dequeue(Fila *f);            // desenfileirar
int filaEstaVazia(Fila *f);
void liberarFila(Fila *f);
void imprimirFila(Fila *f);
int incr(int i);

int main()
{
    Fila *f = cria();
    if (f != NULL)
    {
        enqueue(f, 5);
        enqueue(f, 7);
        enqueue(f, 9);
        enqueue(f, 12);
        enqueue(f, 15);
        imprimirFila(f);
        printf("desenfileirado: %d\n", dequeue(f)); // desenf. 5
        imprimirFila(f);
        enqueue(f, 15);
        imprimirFila(f);
        printf("desenfileirado: %d\n", dequeue(f)); // desenf. 7
        enqueue(f, 17);
        imprimirFila(f);
        liberarFila(f);
    }
    else
    {
        printf("Ocorreu um problema ao tentar criar a fila\n");
        return 1;
    }
    return 0;
}

Fila *cria()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

int filaEstaVazia(Fila *f)
{
    return f->ini == f->fim;
}

void liberarFila(Fila *f)
{
    free(f);
}

// incremento circular
int incr(int i)
{
    return (i + 1) % N;
}

void imprimirFila(Fila *f)
{
    if (filaEstaVazia(f))
    {
        printf("Fila vazia!!\n");
        return;
    }
    printf("Elementos na fila:\n");
    printf("ini: %d\n", f->ini);
    printf("fim: %d\n", f->fim);
    for (int i = f->ini; i != f->fim; i = incr(i))
    {
        printf("%d <- ", f->elems[i]);
    }
    printf("\n\n");
}
// enfileirar
void enqueue(Fila *f, int elem)
{
    if (incr(f->fim) == f->ini)
    {
        printf("fila cheia - queue overflow!!!\n");
        return;
    }

    f->elems[f->fim] = elem;
    f->fim = incr(f->fim);
}

int dequeue(Fila *f)
{
    int ret = -1;
    if (filaEstaVazia(f))
    {
        printf("Fila vazia - queue underflow!!!\n");
        return -1;
    }

    ret = f->elems[f->ini];
    f->elems[f->ini] = -1;
    f->ini = incr(f->ini);
    return ret;
}
