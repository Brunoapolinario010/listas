#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

#define MAX 101

typedef struct _node {
  char value;
  struct _node *next;
} Node;

typedef struct _linkedstack {
  Node *top;
} LinkedStack;

LinkedStack *linkedstack_init();
int linkedstack_empty(LinkedStack *stack);
void linkedstack_push(LinkedStack *stack, char value);
char linkedstack_pop();
void linkedstack_print(Node *node);
void linkedstack_print_iterative(Node *node);
void linkedstack_free();
char *infix_to_postfix(char *infix);
float calculate_postfix_expression(char *postfix);

#endif