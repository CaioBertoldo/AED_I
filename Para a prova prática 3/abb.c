#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


// Função para inicializar a árvore
void inicializa_arvore(ARVORE* a){
    a->raiz = NULL;
}

// Função para criar um nó
NO* criarNo(int n){
    NO* novo = malloc(sizeof(NO));
    novo->num = n;
    novo->direita = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir um nó 
NO* inserir(NO* raiz, NO* no){
    if(raiz == NULL){
        return no;
    }
    if(raiz->num > no->num){
        raiz->esquerda = inserir(raiz->esquerda, no);
    } else{
        raiz->direita = inserir(raiz->direita, no);
    }
    return raiz;
}

// Função para adicionar o nó na árvore
int adiciona(ARVORE* a, int n){
    a->raiz = inserir(a->raiz, criarNo(n));
    return 1;
}

// Função para fazer uma busca de um nó na árvore
NO* busca(NO* raiz, int n){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->num == n){
        return raiz;
    }
    if(raiz->num > n){
        return busca(raiz->esquerda, n);
    } else {
        return busca(raiz->direita, n);
    }
}

// Função para buscar na árvore
NO* buscar_arvore(ARVORE* a, int n){
    return busca(a->raiz, n);
}

// Fazer a contagem do número de elementos
int numeroNos(NO* raiz){
    if(!raiz){
        return 0;
    }
    return numeroNos(raiz->esquerda) + 1 + numeroNos(raiz->direita);
}

// Percorrer os nós em pre ordem
void pre_ord(NO* raiz){
    if(!raiz){
        return;
    }
    printf("%d ", raiz->num);
    pre_ord(raiz->esquerda);
    pre_ord(raiz->direita);
}

// Imprimir a árvore em pre ordem
void mostrar_pre_ordem(ARVORE* a){
    return pre_ord(a->raiz);
}

// Percorrer os nós em in ordem
void in_ord(NO* raiz){
    if(!raiz){
        return;
    }
    in_ord(raiz->esquerda);
    printf("%d ",raiz->num);
    in_ord(raiz->direita);
}

// imprimir a árvore em in ordem
void mostrar_in_ordem(ARVORE* a){
    return in_ord(a->raiz);
}

// Percorrer os nós em pós ordem
void pos_ord(NO* raiz){
    if(!raiz){
        return;
    }
    pos_ord(raiz->esquerda);
    pos_ord(raiz->direita);
    printf("%d ", raiz->num);
}

// Mostrar a árvore em pos ordem
void mostrar_pos_ordem(ARVORE*a){
    return pos_ord(a->raiz);
}