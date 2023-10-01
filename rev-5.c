#include <stdio.h>

typedef struct aluno {
  int matricula;
  char nome[50];
  float nota1;
  float nota2;
  float nota3;
} Aluno;

void main() {
  Aluno alunos[5];
  float media[5];
  int indexMaiorMedia = 0;

  for(int i = 0; i < 5; i++) {
    alunos[i].matricula = i + 1;
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf("%s", alunos[i].nome);
    printf("Digite a nota 1 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota1);
    printf("Digite a nota 2 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota2);
    printf("Digite a nota 3 do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota3);
    printf("\n");
  }

  for(int i = 0; i < 5; i++) {
    media[i] = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
  }

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(media[i] > media[j]) {
        indexMaiorMedia = i;
      }
    }
  }

  printf("Aluno com maior media: %s\n", alunos[indexMaiorMedia].nome);
  printf("Matricula: %d\n", alunos[indexMaiorMedia].matricula);
  printf("Media: %f\n", media[indexMaiorMedia]);
}