#include <stdio.h>

typedef struct ponto {
  float x;
  float y;
} Ponto;

void main() {
  Ponto p1, origem = {0, 0};
  float dist;
  printf("Digite as coordenadas do ponto: ");
  scanf("%f %f", &p1.x, &p1.y);

  printf("p1: %f, %f\n", p1.x, p1.y);
  printf("origem: %f, %f\n", origem.x, origem.y);

  dist = (origem.x - p1.x) * (origem.x - p1.x) + (origem.y - p1.y) * (origem.y - p1.y);

  printf("Distancia: %f\n", dist);
}