#include <stdio.h>

void trocarDiagonal(int *mat, int tamanho) {
    int somaDiagonalSec = 0;
    int contDiagonalSec = 0;

    for (int i = 0; i < tamanho; i++) {
        somaDiagonalSec += mat[i * tamanho + (tamanho - 1 - i)];
        contDiagonalSec++;
    }

    float mediaDiagonalSec = somaDiagonalSec / contDiagonalSec;

    for (int i = 0; i < tamanho; i++) {
        mat[i * tamanho + i] = mediaDiagonalSec;
    }
}

void main() {
    int mat[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor da posição %dx%d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    trocarDiagonal(&mat[0][0], 3);

    printf("Matriz com diagonal substituída:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}