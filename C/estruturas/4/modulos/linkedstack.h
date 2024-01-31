#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "base.h"

typedef struct linkedstack {
    Node *top;
} LinkedStack;

LinkedStack *linkedstack_create();

void linkedstack_push(LinkedStack *stack, char *data);

char *linkedstack_pop(LinkedStack *stack);

int linkedstack_contains(LinkedStack *stack, char *word);

int linkedstack_free(LinkedStack *stack);

#endif