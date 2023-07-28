#include <stdio.h>
#include <stdlib.h>
#include "Inteiros.h"

int main(){
    Lista *l1;
    criar(l1);

    int size;
    inserir_elemento_ord(l1, 3);
    inserir_elemento_ord(l1, 2);
    inserir_elemento_ord(l1, 6);
    size = tamanho_lista(l1);
    printf("\n %d", size);
    imprimir_lista(l1);

    return 0;
}