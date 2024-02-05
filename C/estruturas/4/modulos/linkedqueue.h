#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "base.h"

typedef struct _linkedqueue {
    Node *front;
    Node *tail;
} LinkedQueue;

LinkedQueue *linkedqueue_create();

void linkedqueue_enqueue(LinkedQueue *queue, char *data);

char *linkedqueue_dequeue(LinkedQueue *queue);

int linkedqueue_free(LinkedQueue *queue);

#endif