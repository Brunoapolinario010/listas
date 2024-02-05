#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack *linkedstack_create() {
  LinkedStack *stack = (LinkedStack*) malloc(sizeof(LinkedStack));

  if(stack == NULL) {
    printf("[STACK] Erro ao alocar memoria para Stack!\n");
    exit(1);
  }

  stack->top = NULL;
  return stack;
}

void linkedstack_push(LinkedStack *stack, char *data) {
  Node *node = (Node*) malloc(sizeof(Node));

  if(node == NULL) {
    printf("[STACK] Erro ao alocar memoria para Node!\n");
    exit(1);
  }

  int len = strlen(data);
  char *word = (char*) malloc(sizeof(char) * (len + 1));

  if(word == NULL) {
    printf("[STACK] Erro ao alocar memoria para palavra!\n");
    exit(1);
  }
  
  strcpy(word, data);

  node->data = word;
  node->next = stack->top;
  stack->top = node;
}

char *linkedstack_pop(LinkedStack *stack) {
  if(stack->top == NULL) {
    printf("[STACK] Pilha vazia!\n");
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