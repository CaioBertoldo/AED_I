#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main(){
    ARVORE a;
    inicializa_arvore(&a);
    // 24, 10, 32, 5, 12, 29, 35
    
    NUMERO n;
    n.num = 24;
    NO* novo = criar_no(n);
    adiciona(&a, novo);
    

    NUMERO n2;
    n2.num = 10;
    NO* novo2 = criar_no(n2);
    adiciona(&a, novo2);

    NUMERO n3;
    n3.num = 32;
    NO* novo3 = criar_no(n3);
    adiciona(&a, novo3);

    NUMERO n4;
    n4.num = 5;
    NO* novo4 = criar_no(n4);
    adiciona(&a, novo4);

    NUMERO n5;
    n5.num = 12;
    NO* novo5 = criar_no(n5);
    adiciona(&a, novo5);

    NUMERO n6;
    n6.num = 29;
    NO* novo6 = criar_no(n6);
    adiciona(&a, novo6);

    NUMERO n7;
    n7.num = 35;
    NO* novo7 = criar_no(n7);
    adiciona(&a, novo7);

    printf("\nArvore: ");
    imprimir_arvore(&a);
    linha();

    printf("\nTotal de elementos na arvore: %d", numero_nos(a.raiz));
    linha();

    NO* result = buscar_arvore(&a, 10);
    printf("\nResultado da busca: ");
    printf("\nNo resultado direita: %d", result->direita->num);
    printf("\nNo resultado: %d", result->num.num);
    printf("\nNo resultado esquerda: %d", result->esquerda->num);
    linha();

    printf("\nArvore percorrida em pre ordem: ");
    mostrar_pre_ordem(&a);
    linha();

    printf("\nArvore percorrida em in ordem: ");
    mostrar_in_ordem(&a);
    linha();

    printf("\nArvore percorrida em pos ordem: ");
    mostrar_pos_ordem(&a);
    linha();
    
    return 0;
}