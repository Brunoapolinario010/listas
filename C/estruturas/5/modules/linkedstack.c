#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedstack.h"

LinkedStack *linkedstack_init() {
  LinkedStack *stack = (LinkedStack *) malloc(sizeof(LinkedStack));

  if(stack == NULL) {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }

  stack->top = NULL;
  return stack;
}

int linkedstack_empty(LinkedStack *stack) {
  return stack->top == NULL;
}

void linkedstack_push(LinkedStack *stack, char value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = stack->top;

  stack->top = node;
}

char linkedstack_pop(LinkedStack *stack) {
  if (stack->top == NULL) {
    printf("A stack esta vazia\n");
    return '\0';
  }

  Node *node = stack->top;
  char value = node->value;

  stack->top = node->next;
  free(node);

  return value;
}

void linkedstack_print(Node *node) {
  if (node == NULL) {
    return;
  }

  linkedstack_print(node->next);
  printf("%c", node->value);
}

void linkedstack_print_iterative(Node *node) {
  while (node != NULL) {
    printf("%c", node->value);
    node = node->next;
  }
}

int operator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
  switch(c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
  }
  return 0;
}

char *infix_to_postfix(char *infix) {
  LinkedStack *aux = linkedstack_init();

  int len = strlen(infix);
  char c;
  char *postfix = (char *)malloc(len * sizeof(char));
  int j = 0;

  for (int i = 0; i < len; i++) {
    c = infix[i];
    if (c >= '0' && c <= '9') {
      postfix[j++] = c;
    } else if (c == '(') {
      linkedstack_push(aux, c);
    } else if (c == ')') {
      while (!linkedstack_empty(aux) && aux->top->value != '(') {
        postfix[j++] = linkedstack_pop(aux);
      }
      linkedstack_pop(aux);
    } else if (operator(c)) {
      while (!linkedstack_empty(aux) && precedence(aux->top->value) >= precedence(c)) {
        postfix[j++] = linkedstack_pop(aux);
      }
      linkedstack_push(aux, c);
    }
  }

  while (!linkedstack_empty(aux)) {
    postfix[j++] = linkedstack_pop(aux);
  }

  postfix[j] = '\0';
  linkedstack_free(aux);

  return postfix;
}

float calculate_postfix_expression(char *postfix) {
  LinkedStack *aux = linkedstack_init();
  int len = strlen(postfix);
  char c;
  float a, b, result;

  for (int i = 0; i < len; i++) {
    c = postfix[i];
    if (c >= '0' && c <= '9') {
      linkedstack_push(aux, (float) c - '0');
    } else if (operator(c)) {
      a = linkedstack_pop(aux);
      b = linkedstack_pop(aux);
      switch (c) {
        case '+':
          result = a + b;
          break;
        case '-':
          result = b - a;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          result = b / a;
          break;
      }
      linkedstack_push(aux, result);
    }
  }

  linkedstack_free(aux);
  
  return result;
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