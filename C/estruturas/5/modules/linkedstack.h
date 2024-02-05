#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

typedef struct _node {
  char value;
  struct _node *next;
} Node;

typedef struct _linkedstack {
  Node *top;
} LinkedStack;

LinkedStack *linkedstack_init();
void linkedstack_push(LinkedStack *stack, char value);
char linkedstack_pop();
void linkedstack_print();
void linkedstack_free();
LinkedStack *infix_to_postfix(LinkedStack *postfix, LinkedStack *infix);

#endif