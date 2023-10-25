#include <stdio.h>

void equalizar(int *x, int *y, int *z) {
    float media, resto;

    media = (*x + *y + *z) / 3;
    resto = (*x + *y + *z) % 3;

    *x = *x * (media / *x);
    *y = *y * (media / *y);
    *z = *z * (media / *z);

    if(resto > 0) {
        if(resto > 1) {
            *y += resto / 2;
            *z += resto / 2;
        } else {
            *z += resto;
        }
    }
}

void main() {
    int a, b, c;

    printf("Digite 3 valores: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("original: %d, %d, %d\n", a, b, c);
    equalizar(&a, &b, &c);
    printf("equalizado: %d, %d, %d\n", a, b, c);
}