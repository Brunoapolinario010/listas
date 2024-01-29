#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

LinkedQueue *linkedqueue_create() {
  LinkedQueue *queue = (LinkedQueue*) malloc(sizeof(struct linkedqueue));

  if(queue == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  queue->front = NULL;
  queue->tail = NULL;
  return queue;
}

void linkedqueue_enqueue(LinkedQueue *queue, char data) {
  Node *node = (Node*) malloc(sizeof(struct node));

  if(node == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  node->data = data;
  node->next = NULL;

  if(queue->front == NULL) {
    queue->front = node;
  } else {
    queue->tail->next = node;
  }

  queue->tail = node;
}

char linkedqueue_dequeue(LinkedQueue *queue) {
  if(queue->front == NULL) {
    printf("Fila vazia!\n");
    exit(1);
  }

  Node *node = queue->front;
  char data = node->data;
  queue->front = node->next;

  if(queue->front == NULL) {
    queue->tail = NULL;
  }

  free(node);
  return data;
}

int linkedqueue_free(LinkedQueue *queue) {
  Node *node = queue->front;
  Node *aux;

  while(node != NULL) {
    aux = node->next;
    free(node);
    node = aux;
  }

  free(queue);
  return 1;
}