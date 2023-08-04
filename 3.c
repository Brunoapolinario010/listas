#include <stdio.h>

int fatorial (int valor) {
    int resultado = 1;

    if (valor == 0 || valor == 1) {
        return 1;
    } else {
        for (int i = 1; i <= valor; i++) {
            resultado *= i;
        }
    }

    return resultado;
}

void main () {
    int valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);

    if(valor < 0) {
        printf("Não existe fatorial de número negativo\n");
    } else {
        printf("O fatorial de %d é %d\n", valor, fatorial(valor));
    }

}