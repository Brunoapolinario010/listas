#include <stdio.h>
#include "./modules/linkedstack.h"

int main() {
  LinkedStack *infix;
  LinkedStack *postfix;
  LinkedStack *result;

  linkedstack_init(infix);
  linkedstack_init(postfix);
  linkedstack_init(result);

  char c;
  while(scanf("%c", &c) != EOF) {
    linkedstack_push(infix, c);
    linkedstack_push(postfix, c);
  }

  linkedstack_print(infix->top);

  linkedstack_free(infix);
  linkedstack_free(postfix);
  linkedstack_free(result);
  return 0;
}