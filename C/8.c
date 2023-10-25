#include <stdio.h>

char proxcar(int x, char y) {
    return y + x;
}

int main()
{
int x;
char y;
y = 'a';
printf("Digite um número: ");
scanf("%d", &x);
printf("O %dº caracter depois de %c é: %c\n", x, y, proxcar(x,y));

y = proxcar('b',3);

printf("O %dº caracter depois de %c é: %c\n", 3, 'b', y);
}