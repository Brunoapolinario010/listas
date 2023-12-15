#include <stdio.h>
#include <stdbool.h>

bool primo (int valor) {
    int divisores = 0;

    for (int i = 1; i <= valor; i++) {
        if (valor % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        return true;
    }

    return false;
}

int nPrimos (int n) {
    if (n == 1) return 2;

    int count = 1;
    int num = 3;
    int ultimoPrimo = 0;

    while (count < n) {
        if (primo(num)) {
            count++;
            ultimoPrimo = num;
        }
        num += 2;
    }

    return ultimoPrimo;
}

void main () {
    int n;

    printf("Digite qual a posição do número primo: ");
    scanf("%d", &n);

    printf("O %d primo é: %d\n", n, nPrimos(n));
}