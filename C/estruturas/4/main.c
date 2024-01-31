#include <stdio.h>
#include "./modulos/linkedstack.h"
#include "./modulos/linkedqueue.h"

#define MAX 41

int main() {
  LinkedStack *stack = linkedstack_create();
  LinkedQueue *queue = linkedqueue_create();
  char palavra[MAX];
  int aux = 0;

  while (scanf("%s", palavra) != EOF) {
    linkedqueue_enqueue(queue, palavra);

    if (!linkedstack_contains(stack, palavra)) {
      linkedstack_push(stack, palavra);
    }
  }

  printf("Texto original:\n");
  while (queue->front != NULL) {
    printf("%s ", linkedqueue_dequeue(queue));
    aux++;
  }
  printf("\nTotal de palavras: %d\n", aux);

  aux = 0;

  printf("Palavras diferentes:\n");
  while (stack->top != NULL) {
    printf("%s ", linkedstack_pop(stack));
    aux++;
  }
  printf("\nTotal de palavras diferentes: %d\n", aux);

  linkedqueue_free(queue);
  linkedstack_free(stack);
  return 0;
}