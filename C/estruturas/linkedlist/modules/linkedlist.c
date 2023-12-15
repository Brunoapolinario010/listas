#include <stdio.h>
#include <stdlib.h>
#include "./linkedlist.h"

void init_linkedlist(LinkedList *list)
{
  list->first = NULL;
  list->size = 0;
}

void insert(LinkedList *list, int data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (list->first == NULL)
  {
    list->first = new_node;
  }
  else
  {
    Node *current = list->first;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = new_node;
  }
  list->size++;
}

void remove_node(LinkedList *list, int data)
{
  Node *current = list->first;
  Node *previous = NULL;
  while (current != NULL && current->data != data)
  {
    previous = current;
    current = current->next;
  }
  if (current != NULL)
  {
    if (previous == NULL)
    {
      list->first = current->next;
    }
    else
    {
      previous->next = current->next;
    }
    free(current);
    list->size--;
  }
}

void print_linkedlist(LinkedList *list)
{
  Node *current = list->first;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}