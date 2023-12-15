#include <stdio.h>
#include "./modules/linkedlist.h"

int main()
{
  LinkedList list;
  init_linkedlist(&list);
  insert(&list, 1);
  insert(&list, 2);
  insert(&list, 3);
  insert(&list, 4);
  insert(&list, 5);
  print_linkedlist(&list);
  remove_node(&list, 3);
  print_linkedlist(&list);

  return 0;
}