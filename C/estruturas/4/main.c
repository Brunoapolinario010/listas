#include <stdio.h>
#include "./modulos/linkedstack.h"
#include "./modulos/linkedqueue.h"

int main() {
  LinkedStack *stack = linkedstack_create();
  LinkedQueue *queue = linkedqueue_create();
  char palavra;
  while (scanf("%c", &palavra) != EOF) {
    linkedqueue_enqueue(queue, palavra);

    if (!linkedstack_contains(stack, &palavra)) {
      linkedstack_push(stack, palavra);
    }
  }

  printf("Texto original:\n");
  while (queue->front != NULL) {
    printf("%c", linkedqueue_dequeue(queue));
  }

  printf("Palavras diferentes:\n");
  while (stack->top != NULL) {
    printf("%c", linkedstack_pop(stack));
  }

  linkedqueue_free(queue);
  linkedstack_free(stack);
  return 0;
}