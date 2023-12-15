#include <stdio.h>

void main() {
  int vet[15];
  int valor;

  printf("Digite 15 valores inteiros:\n");
  for(int i = 0; i < 15; i++) {
    scanf("%d", &vet[i]);
  }

  printf("Qual valor deseja buscar no vetor?\n");
  scanf("%d", &valor);
  for(int i = 0; i < 15; i++) {
    if (vet[i] == valor) {
      printf("O valor %d está na posição %d do vetor.\n", valor, i);
      return;
    }
    if(i == 14) printf("O valor %d não está no vetor.\n", valor);
  }
}