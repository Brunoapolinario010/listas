#include <stdio.h>

typedef struct hora {
  int hora;
  int minuto;
  int segundo;
} Hora;

void main() {
  Hora h[5];
  int indexMaiorHora = 0;

  for(int i = 0; i < 5; i++) {
    printf("Digite a hora %d: ", i + 1);
    scanf("%d", &h[i].hora);
    printf("Digite o minuto %d: ", i + 1);
    scanf("%d", &h[i].minuto);
    printf("Digite o segundo %d: ", i + 1);
    scanf("%d", &h[i].segundo);
    printf("\n");
  }

  for (int i = 1; i < 5; i++) {
    if (h[i].hora > h[indexMaiorHora].hora) {
      indexMaiorHora = i;
    }
    else if (h[i].hora == h[indexMaiorHora].hora) {
      if (h[i].minuto > h[indexMaiorHora].minuto) {
        indexMaiorHora = i;
      }
      else if (h[i].minuto == h[indexMaiorHora].minuto) {
        if (h[i].segundo > h[indexMaiorHora].segundo) {
          indexMaiorHora = i;
        }
      }
    }
  }

  printf("A maior hora é: %d:%d:%d\n", h[indexMaiorHora].hora, h[indexMaiorHora].minuto, h[indexMaiorHora].segundo);
}