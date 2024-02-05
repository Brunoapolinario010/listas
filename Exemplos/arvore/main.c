#include <stdio.h>
#include "./modules/arv.h"

int main() {
  Arv* a = arv_cria('a', 
    arv_cria('b', 
      arv_inicializa(), 
      arv_cria('d', 
        arv_inicializa(), 
        arv_inicializa()
      )
    ), 
    arv_cria('c', 
      arv_cria('e', 
        arv_inicializa(), 
        arv_inicializa()
      ),
      arv_cria('f', 
        arv_inicializa(), 
        arv_inicializa()
      )
    )
  );

  arv_imprime(a);

  return 0;
}