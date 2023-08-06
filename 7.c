#include <math.h>
#include <stdio.h>

void equalizar(int *x, int *y, int *z) {
    float media, fatorX, fatorY, fatorZ;

    media = (*x + *y + *z) / 3.0;
    fatorX = media / *x;
    fatorY = media / *y;
    fatorZ = media / *z;

    *x = round(*x * fatorX);
    *y = round(*y * fatorY);
    *z = round(*z * fatorZ);
}

void main() {
    int a, b, c;

    printf("Digite 3 valores: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("original: %d, %d, %d\n", a, b, c);
    equalizar(&a, &b, &c);
    printf("equalizado: %d, %d, %d\n", a, b, c);
}