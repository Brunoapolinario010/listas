#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

void main() {
    printf("Teste Instanciar Função\n");
    int resultado = soma(5, 2);
    printf("Resultado: %d\n", resultado);
}