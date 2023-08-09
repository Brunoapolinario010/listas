#include <stdio.h>

void consoanteMaiuscula (char *p) {
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] >= 'a' && p[i] <= 'z') {
            if (p[i] != 'a' && p[i] != 'e' && p[i] != 'i' && p[i] != 'o' && p[i] != 'u') {
                p[i] = p[i] - 32;
            }
        }
    }
}

void main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    consoanteMaiuscula(palavra);
    printf("A palavra modificada será %s\n", palavra);
}