#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

Arv *arv_inicializa() {
  return NULL;
}

Arv *arv_cria(char c, Arv *sae, Arv *sad) {
  Arv *p = (Arv *)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int arv_vazia(Arv* a) {
  return a == NULL;
}

void arv_imprime(Arv* a) {
  if(!arv_vazia(a)) {
    printf("%c ", a->info);
    arv_imprime(a->esq);
    arv_imprime(a->dir);
  }
}