#include <stdio.h>
/**
    Compile este exemplo utilizando: gcc -Wall ex2_redir_entrada.c
    - Execute utilizando:
        -- No Linux: ./a.out < in2.txt
        -- No Windows: ./a.exe < in2.txt
*/

int main() {
    int valor;
    while (scanf("%d", &valor) != EOF) {
        printf("%d\n", valor);
    }
    return 0;
}
