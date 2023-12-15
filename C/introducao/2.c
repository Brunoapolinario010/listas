#include <stdio.h>

void menorQue(int *vetor, int valor) {
    for (int i = 0; i < 10; i++) {
        vetor[i] = valor-i;
    }
}

void main() {
    int vetor[10];
    int limite;

    printf("Digite um valor: ");
    scanf("%d", &limite);

    menorQue(vetor, limite);
    printf("O vetor de números menores que %d em sequência será será:\n", limite);
    for (int i = 0; i < 10; i++) {
        printf("%d:%d\n", i+1, vetor[i]);

    }
}