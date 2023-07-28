#include <stdio.h>
#include <stdlib.h>
#include "Lista_inteiros.h"

int main(){

    LISTA *list = criar(5);

    inserir_elementos(list, 3);
    inserir_elementos(list, 9);
    inserir_elementos(list, 2);
    inserir_elementos(list, 5);
    inserir_elementos(list, 6);

    printf("\n---- LISTA NAO ORDENADA ----\n");
    imprimir_lista(list);

    LISTA *l2 = criar(4);
    inserir_elemento_ordenado(l2, 5);
    inserir_elemento_ordenado(l2, 2);
    inserir_elemento_ordenado(l2, 8);
    inserir_elemento_ordenado(l2, 4);

    printf("\n---- LISTA ORDENADA ----\n");
    if(lista_vazia(l2)) printf("vazia\n.");
    imprimir_lista(l2);

    excluir_elemento_pos(list, 2);
    printf("\n---- LISTA COM O ELEMENTO DA POSICAO 2 EXLUICO ----\n");
    imprimir_lista(list);

    printf("\n\n %d \n\n", busca_binaria(list, 9));

    liberar(list);
    liberar(l2);
    return 0;
}
