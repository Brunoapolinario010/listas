#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./modules/linkedstack.h"

int main() {
  char *infix = (char *) malloc(MAX * sizeof(char));
  char *postfix = (char *) malloc(MAX * sizeof(char));
  float result;
  char c;

  int len = 0;
  while(scanf("%c", &c) != EOF) {
    if(c != ' ') {
      infix[len++] = c;
    }

    if(c == '\n' || c == '\0') {
      infix[len] = '\0';
      break;
    }

    if(len == MAX) {
      printf("Tamanho maximo de caracteres atingido\n");
      return 1;
    }
  }

  printf("Infixa: ");
  for(int i = 0; infix[i] != '\0'; i++) {
    printf("%c", infix[i]);
  }

  postfix = infix_to_postfix(infix);
  printf("Posfixa: ");
  for(int i = 0; postfix[i] != '\0'; i++) {
    printf("%c", postfix[i]);
  }

  result = calculate_postfix_expression(postfix);
  printf("\nResultado: %.2f\n", result);

  free(infix);
  free(postfix);
  return 0;
}
