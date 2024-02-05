#ifndef ARV_H
#define ARV_H

typedef struct _arv {
  char info;
  struct _arv *esq;
  struct _arv *dir;
} Arv;

Arv* arv_inicializa();

Arv* arv_cria(char c, Arv* e, Arv* d);

int arv_vazia(Arv* a);

void arv_imprime(Arv* a);

#endif