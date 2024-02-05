#include <stdio.h>
#include <stdlib.h>
#include "./linkedstack.h"

void linkedstack_init(LinkedStack *stack) {
  stack = (LinkedStack *)malloc(sizeof(LinkedStack));

  if(stack == NULL) {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }

  stack->top = NULL;
}

void linkedstack_push(LinkedStack *stack, char value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = stack->top;

  stack->top = node;
}

char linkedstack_pop(LinkedStack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return '\0';
  }

  Node *node = stack->top;
  char value = node->value;

  stack->top = node->next;
  free(node);

  return value;
}

// recursive print
void linkedstack_print(Node *node) {
  if (node == NULL) {
    return;
  }

  printf("%c", node->value);
  linkedstack_print(node->next);
}

void linkedstack_free(LinkedStack *stack) {
  Node *node = stack->top;
  Node *next;

  while (node != NULL) {
    next = node->next;
    free(node);
    node = next;
  }

  free(stack);
}