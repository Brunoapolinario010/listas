#include <stdio.h>
#include "./modules/linkedstack.h"

int main() {
  LinkedStack *infix = linkedstack_init();
  LinkedStack *postfix = linkedstack_init();
  LinkedStack *result = linkedstack_init();

  char c;
  while (scanf("%c", &c) != EOF) {
    if (c != ' ') {
      linkedstack_push(infix, c);
    }
  }

  printf("Infixa: ");
  linkedstack_print(infix->top);
  
  infix_to_postfix(postfix, infix);
  
  printf("Posfixa: ");
  linkedstack_print(postfix->top);

  linkedstack_free(infix);
  linkedstack_free(postfix);
  linkedstack_free(result);
  return 0;
}
