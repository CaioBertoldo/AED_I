#include <stdio.h>
#include "Inteiros.h"

int main(){
    Lista *l1;
    criar(l1);

    printf("\n---- LISTA ORDENADA ----\n");
    inserir_elemento_ord(l1, 3);
    inserir_elemento_ord(l1, 4);
    inserir_elemento_ord(l1, 7);
    inserir_elemento_ord(l1, 2);
    imprimir_lista(l1);

    Lista *l2;
    criar(l2);

    printf("\n---- LISTA NAO ORDENADA ----\n");
    inserir_elemento(l2, 9);
    inserir_elemento(l2, 3);
    inserir_elemento(l2, 5);
    imprimir_lista(l2);

    reinicializar(l1);
    reinicializar(l2);
    return 0;
}
