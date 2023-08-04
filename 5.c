#include <stdio.h>

char troca(int *a, int *b) {
    int temp;

    if (*a == *b) {
        return printf("false\n");
    }

    temp = *a;
    *a = *b;
    *b = temp;
    return printf("true\n");
}

void main() {
    int num1 = 3;
    int num2 = 4;

    printf("Números iniciais: %d, %d\n", num1, num2);

    troca(&num1, &num2);

    printf("Números trocados: %d, %d\n", num1, num2);
}