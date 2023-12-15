#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

typedef struct _linkedlist
{
  Node *first;
  int size;
} LinkedList;

void init_linkedlist(LinkedList *list);

void insert(LinkedList *list, int data);

void remove_node(LinkedList *list, int data);

void print_linkedlist(LinkedList *list);

#endif