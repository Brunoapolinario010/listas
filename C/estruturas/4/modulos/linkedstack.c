#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack *linkedstack_create() {
  LinkedStack *stack = (LinkedStack*) malloc(sizeof(struct linkedstack));

  if(stack == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  stack->top = NULL;
  return stack;
}

void linkedstack_push(LinkedStack *stack, char *data) {
  Node *node = (Node*) malloc(sizeof(struct node));

  if(node == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  int size = 0;
  while(data[size] != '\0') {
    size++;
  }

  char *word = (char*) malloc((size + 1) * sizeof(char));
  for(int i = 0; i < size; i++) {
    word[i] = data[i];
  }
  word[size] = '\0';

  node->data = word;
  node->next = stack->top;
  stack->top = node;
}

char *linkedstack_pop(LinkedStack *stack) {
  if(stack->top == NULL) {
    printf("Pilha vazia!\n");
    exit(1);
  }

  Node *node = stack->top;
  char *data = node->data;
  stack->top = node->next;
  free(node);
  return data;
}

int linkedstack_contains(LinkedStack *stack, char *word) {
  Node *node = stack->top;
  while(node != NULL) {
    if(strcmp(node->data, word) == 0){
      return 1;
    }
    node = node->next;
  }
  return 0;
}

int linkedstack_free(LinkedStack *stack) {
  Node *node = stack->top;
  Node *aux;

  while(node != NULL) {
    aux = node->next;
    free(node);
    node = aux;
  }

  free(stack);
  return 1;
}