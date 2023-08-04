#include <stdio.h>

void ordenar(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

void main() {
    int num1 = 3;
    int num2 = 5;
    int num3 = 1;

    printf("Números iniciais: %d, %d, %d\n", num1, num2, num3);

    ordenar(&num1, &num2, &num3);

    printf("Números ordenados: %d, %d, %d\n", num1, num2, num3);
}