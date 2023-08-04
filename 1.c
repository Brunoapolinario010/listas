#include <stdio.h>

void consoanteMaiuscula (char *p) {
    char vogais[] = "AEIOUaeiou";

    for (int i = 0; p[i] != '\0'; i++) {
        for (int j = 0; vogais[j] != '\0'; j++) {
            if (p[i] != vogais[j] && p[i] >= 'a' && p[i] <= 'z') {
                p[i] = p[i] - 32;
                break;
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