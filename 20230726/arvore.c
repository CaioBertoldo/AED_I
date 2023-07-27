#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Inicializar a árvore
void inicializa_arvore(ARVORE* a){
    a->raiz = NULL;
}

// Criar um nó 
NO* criar_no(NUMERO n){
    NO* novo_no = malloc(sizeof(NO));
    novo_no->num = n;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Inserir o nó na árvore
NO* inserir(NO* raiz, NO* no){
    if(raiz == NULL){
        return no;
    }
    if(raiz->num.num > no->num.num){
        raiz->esquerda = inserir(raiz->esquerda, no);
    } else{
        raiz->direita = inserir(raiz->direita, no);
    }
    return raiz;
}

// Adicioonar na árvore
int adiciona(ARVORE* a, NO* novo){
    a->raiz = inserir(a->raiz, novo);
    return 1;
}

// Imprimir os nós da árvore
void imprimir_nos(NO* raiz){
    if(raiz != NULL){
        imprimir_nos(raiz->esquerda);
        printf("%d ", raiz->num.num);
        imprimir_nos(raiz->direita);
    }
}

// Imprimir os elementos da árvore
void imprimir_arvore(ARVORE* a){
    imprimir_nos(a->raiz);
}

// Contar quantos elementos tem na árvore
int numero_nos(NO* raiz){
    if(!raiz){
        return 0;
    }
    return (numero_nos(raiz->esquerda) + 1 + numero_nos(raiz->direita));
}

// Função de buscar nós
NO* busca(NO* raiz, int n){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->num.num == n){
        return raiz;
    }

    if(raiz->num.num > n){
        return busca(raiz->esquerda, n);
    } else{
        return busca(raiz->direita, n);
    }
}

// Função de buscar na árvore
NO* buscar_arvore(ARVORE* a, int n){
    return busca(a->raiz, n);
}

// linha
void linha(){
    printf("\n----------------------------\n");
}

// Percorrer a árvore em pré ordem
void pre_ordem(NO* raiz){
    if(!raiz){
        return;
    }
    printf("%d ", raiz->num.num);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

// Mostrar na árvore pre ordem
void mostrar_pre_ordem(ARVORE* a){
    return pre_ordem(a->raiz);
}

// Percorre in ordem
void in_ordem(NO* raiz){
    if(!raiz){
        return;
    }
    in_ordem(raiz->esquerda);
    printf("%d ", raiz->num.num);
    in_ordem(raiz->direita);
}

// Mostrar na árvore em in ordem
void mostrar_in_ordem(ARVORE* a){
    return in_ordem(a->raiz);
}

// Percorrer arvore pos ordem
void pos_ordem(NO* raiz){
    if(!raiz){
        return;
    }
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->num.num);
}

// Mostrar na árvore em pos ordem
void mostrar_pos_ordem(ARVORE* a){
    return pos_ordem(a->raiz);
}