#include <stdio.h>
#include <stdlib.h>
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

void linkedstack_push(LinkedStack *stack, char value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = stack->top;

  stack->top = node;
}

char linkedstack_pop(LinkedStack *stack) {
  if (stack->top == NULL) {
    printf("A stack está vazia\n");
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
    printf("\n");
    return;
  }

  linkedstack_print(node->next);
  printf("%c", node->value);
}

int is_operator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int get_precedence(char c) {
  if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  }
  return 0;
}

LinkedStack *infix_to_postfix(LinkedStack *postfix, LinkedStack *infix) {
  Node *node = infix->top;
  char c;
  LinkedStack *operators = linkedstack_init();

  while (node != NULL) {
    c = node->value;
    if (c >= '0' && c <= '9') {
      linkedstack_push(postfix, c);
    } else if (is_operator(c)) {
      while (operators->top != NULL && get_precedence(operators->top->value) >= get_precedence(c)) {
        linkedstack_push(postfix, linkedstack_pop(operators));
      }
      linkedstack_push(operators, c);
    } else if (c == '(') {
      linkedstack_push(operators, c);
    } else if (c == ')') {
      while (operators->top != NULL && operators->top->value != '(') {
        linkedstack_push(postfix, linkedstack_pop(operators));
      }
      linkedstack_pop(operators); // Pop '('
    }
    node = node->next;
  }

  while (operators->top != NULL) {
    linkedstack_push(postfix, linkedstack_pop(operators));
  }

  linkedstack_free(operators);

  return postfix;
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