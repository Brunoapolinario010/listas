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
    int num1, num2;

    printf("Digite o 1 número: ");
    scanf("%d", &num1);
    printf("Digite o 2 número: ");
    scanf("%d", &num2);

    printf("Números iniciais: %d, %d\n", num1, num2);

    troca(&num1, &num2);

    printf("Números trocados: %d, %d\n", num1, num2);
}