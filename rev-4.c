#include <stdio.h>

typedef struct ponto {
  float x;
  float y;
} Ponto;

typedef struct retangulo {
  Ponto pontoSupEsq;
  Ponto pontoInfDir;
} Retangulo;

void main() {
  Retangulo r1;
  float altura, largura, area, perimetro, diagonal;

  printf("Digite as coordenadas do ponto 1: ");
  scanf("%f %f", &r1.pontoSupEsq.x, &r1.pontoSupEsq.y);

  printf("Digite as coordenadas do ponto 2: ");
  scanf("%f %f", &r1.pontoInfDir.x, &r1.pontoInfDir.y);

  altura = r1.pontoSupEsq.y - r1.pontoInfDir.y;
  largura = r1.pontoSupEsq.x - r1.pontoInfDir.x;

  if(altura < 0) altura = altura * (-1);
  if(largura < 0) largura = largura * (-1);

  area = altura * largura;
  perimetro = 2 * (altura + largura);
  diagonal = (altura * altura) + (largura * largura);

  printf("Area: %f\n", area);
  printf("Perimetro: %f\n", perimetro);
  printf("Diagonal: %f\n", diagonal);
}