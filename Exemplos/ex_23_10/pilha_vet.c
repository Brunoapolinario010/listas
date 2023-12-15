#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct _pilha Pilha;

struct _pilha {
    int topo;
    int elems[MAX];
};

// operações fornecidas pelo TAD Pilha
Pilha *cria();
void push(Pilha *p, int e);
int pop(Pilha *p);
int estaVazia(Pilha *p);
void libera(Pilha *p);
void imprimirPilha(Pilha *p);

int main() {
    int elem;
    Pilha *pilha = cria();
    if (pilha != NULL) {
        /*
            O código abaixo deverá ser utilizado com
            o recurso de redirecionamento de entrada (stdin) visto
            em aula.
        */
        while (scanf("%d", &elem) != EOF) {
            push(pilha, elem);
        }
        imprimirPilha(pilha);

        /*
        push(pilha, 3);
        push(pilha, 2);
        push(pilha, 7);
        push(pilha, 5);
        imprimirPilha(pilha);
        printf("elemento desempilhado: %d\n", pop(pilha));
        printf("elemento desempilhado: %d\n", pop(pilha));
        imprimirPilha(pilha);
        printf("elemento desempilhado: %d\n", pop(pilha));
        printf("elemento desempilhado: %d\n", pop(pilha));
        printf("elemento desempilhado: %d\n", pop(pilha));
        imprimirPilha(pilha);
        */
        libera(pilha);
    } else {
        printf("Falha ao tentar criar a pilha\n");
        return 1;
    }

    return 0;
}

Pilha *cria() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = -1;
    }
    return p;
}

void push(Pilha *p, int elem) {
    if (p->topo == MAX - 1) {
        printf("Stack Overflow!!!\n");
        return;
    }        
    p->elems[++p->topo] = elem;
}

int pop(Pilha *p) {
    int ret = -1;
    if (estaVazia(p)) {
        printf("Stack underflow!!!\n");
        return ret;
    }
    ret = p->elems[p->topo--];
    return ret;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void libera(Pilha *p) {
    free(p);
}

void imprimirPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Elementos na pilha:\n");
    printf("Topo: %d\n", p->topo);

    for (int i = p->topo; i >= 0; i--) 
        printf("|%3d|\n", p->elems[i]);
}




