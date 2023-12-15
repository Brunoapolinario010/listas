#include <stdio.h>
/**
    Compile este exemplo utilizando: gcc -Wall ex1_redir_entrada.c
    - Execute utilizando:
        -- No Linux: ./a.out < in1.txt
        -- No Windows: ./a.exe < in1.txt
*/
int main() {
    int quant, valor;
    scanf("%d", &quant);
    for (int i = 0; i < quant; i++) {
        scanf("%d", &valor);
        printf("%d\n", valor);
    }
    return 0;
}
