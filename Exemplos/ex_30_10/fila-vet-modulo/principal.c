#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {
    Fila *f = cria();
    if (f != NULL) {
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
        printf("desenfileirado: %d\n", dequeue(f)); //desenf. 7
        enqueue(f, 17);
        imprimirFila(f);
        liberarFila(f);
    } else {
        printf("Ocorreu um problema ao tentar criar a fila\n");
        return 1;
    }
    return 0;
}
