#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main(){

    // Usuario escolher o tamanho
    int size;
    printf("\nTamanho que voce deseja para o vetor: ");
    scanf("%d", &size);

    // Criar e preencher o vetor 1
    Lista *vector1;
    vector1 = create(size);
    insert_list(vector1);

    // Criar e preencher a lista ordenada
    Lista *vector2;
    vector2 = create(30);
    insert_list_ord(vector2);
    printf("\n");

    // Printar o vetor 1 
    print_list(*vector1);
    printf("\n");

    // Fazer uma busca sequencial no vetor 1
    printf("\n---- FUNCAO PARA BUSCA SEQUENCIAL NA LISTA 1 ----");
    int search;
    printf("\nValor que deseja buscar: ");
    scanf("%d", &search);
    sequential_search(vector1, search);
    printf("\n");

    // Fazer uma busca sequencial na lista ordenada 
    printf("\n---- FUNCAO PARA BUSCA SEQUENCIAL NA LISTA ORDENADA ----");
    int search_ord;
    printf("\nValor que deseja buscar: ");
    scanf("%d", &search_ord);
    sequential_search_ord(vector2, search_ord);
    printf("\n");

    // Fazer uma busca Binária na lista ordenada
    printf("\n---- FUNCAO PARA BUSCA BINARIA NA LISTA ORDENADA ----");
    int search_ord2;
    printf("\nValor que deseja buscar: ");
    scanf("%d", &search_ord2);
    printf("\nValor encontrado na posicao %d", binary_search(vector2, search_ord2));
    if(binary_search(vector2, search_ord2) == -1){
        printf("\nValor nao encontrado");
    }
    printf("\n");

    // Fazer uma busca binária com algoritimo recursivo
    printf("\n---- FUNCAO PARA BUSCA BINARIA COM ALGORITIMO RECURSIVO ----");
    int  search_ord3;
    printf("\nValor que deseja buscar: ");
    scanf("%d", &search_ord3);
    printf("\nValor encontrado na posicao %d", binary_search_recursive(vector2, search_ord3, 0, size, 1) + 1);
    if(binary_search_recursive(vector2, search_ord3, 0, size, 1) == -1){
        printf("\nValor nao encontrado");
    }
    printf("\n");

    // Imprimir uma lista com algoritmo Recursivo
    printf("\n---- FUNCAO PARA IMPRIMIR UMA LISTA COM ALGORITMO RECURSIVO ----\n");
    print_list_recursive(vector1, 0);
    printf("\n");

    // Buscar o maior elemento de uma lista(alogritmo iterativo)
    printf("\n---- FUNCAO PARA BUSCAR O MAIOR ELEMENTO DE UMA LISTA ----\n");
    bigger(vector1);
    printf("\n");

    // Buscar o maior elemento de uma lista(algoritmo recursivo)
    printf("\n---- BUSCAR O MAIOR ELEMENTO DE UMA LISTA (RECURSIVO) ----\n");
    printf("\nO maior elemento da Lista eh %d", bigger_recursive(vector1, size, 0));
    printf("\n");

    // Buscar o menor elemento de uma lista(algoritmo iterativo)
    printf("\n---- BUSCAR O MENOR ELEMENTO DE UMA LISTA (ITERATIVO) ----\n");
    smaller(vector1);
    printf("\n");

    // Buscar o menor elemento de uma lista(recursivo)
    printf("\n---- BUSCAR O MENOR ELEMENTO DE UMA LISTA (RECURSIVO) ----\n");
    printf("\nO menor elemento da lista eh %d", smaller_recursive(vector1, size, 0));
    printf("\n");

    // Soma dos elementos do vetor(iterativo)
    printf("\n---- SOMA DOS ELEMENTOS DE UM VETOR (ITERATIVO) ----\n");
    sum_list(vector1);
    printf("\n");

    // Soma dos elementos do vetor(recursivo)
    printf("\n---- SOMA DOS ELEMENTOS DE UM VETOR (RECURSIVO) ----\n");
    printf("\nSoma dos elementos: %d", sum_list_recursive(vector1, size));
    printf("\n");

    // Produto dos elementos do vetor(iterativo)
    printf("\n---- PRODUTO DOS ELEMENTOS DE UM VETOR(ITERATIVO) ----\n");
    product_list(vector1);
    printf("\n");

    // Produto dos elementos do vetor(recursivo)
    printf("\n---- PRODUTO DOS ELEMENTOS DE UM VETOR(RECURSIVO) ----\n");
    printf("\nProduto dos elementos: %d", product_list_recursive(vector1, size));

    // Liberar a memória alocada
    release(vector1);
    release(vector2);

    return 0;
}
