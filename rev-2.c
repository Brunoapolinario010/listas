#include <stdio.h>

int main() {
  int vet1[10];
  int vet2[10];
  int vet3[10];
  int total = 0;

  printf("Digite 10 valores inteiros para o primeiro vetor:\n");
  for(int i = 0; i < 10; i++) {
    scanf("%d", &vet1[i]);
  }

  printf("Digite 10 valores inteiros para o segundo vetor:\n");
  for(int i = 0; i < 10; i++) {
    scanf("%d", &vet2[i]);
  }

  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(vet1[i] == vet2[j]) {
        vet3[total] = vet1[i];
        printf("vet[%d] = %d\n", total, vet1[i]);
        total++;}
    }
  }

  printf("Os valores em comum entre os vetores são:\n");
  for(int i = 0; i < total; i++) {
    printf("%d\n", vet3[i]);
  }

  return 0;
}