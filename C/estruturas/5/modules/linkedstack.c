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

LinkedStack *infix_to_postfix(LinkedStack *postfix, LinkedStack *infix) {
  Node* node = infix->top;
  LinkedStack* operators = linkedstack_init();
  char c;

  while (node != NULL) {
    c = node->value;
    if (c >= '0' && c <= '9') {
      linkedstack_push(postfix, c);
    } else if (c == '(') {
      linkedstack_push(operators, c);
    } else if (c == ')') {
      while (!linkedstack_empty(operators) && operators->top->value != '(') {
        linkedstack_push(postfix, linkedstack_pop(operators));
      }
      if(!linkedstack_empty(operators)){
        linkedstack_pop(operators);
      }
    } else {
      while (!linkedstack_empty(operators) && operators->top->value != '(' && precedence(operators->top->value) >= precedence(c)) {
        linkedstack_push(postfix, linkedstack_pop(operators));
      }
      linkedstack_push(operators, c);
    }
    node = node->next;
  }

  linkedstack_print_iterative(operators->top);
  while(!linkedstack_empty(operators)) {
    linkedstack_push(postfix, linkedstack_pop(operators));
  }

  return postfix;
}

float calculate_postfix_expression(LinkedStack *postfix) {
  Node *node = postfix->top;
  LinkedStack *result = linkedstack_init();
  char c;
  float operation = 0;
  float a, b;

  while (node != NULL) {
    c = node->value;
    if (c >= '0' && c <= '9') {
      linkedstack_push(result, (float) c - '0');
    } else if (operator(c)) {
      a = linkedstack_pop(result);
      b = linkedstack_pop(result);
      switch (c) {
        case '+':
          operation = a + b;
          break;
        case '-':
          operation = b - a;
          break;
        case '*':
          operation = a * b;
          break;
        case '/':
          operation = b / a;
          break;
      }
      linkedstack_push(result, operation);
    }
    node = node->next;
  }

  return linkedstack_pop(result);
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