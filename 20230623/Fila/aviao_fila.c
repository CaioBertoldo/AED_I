#include <stdio.h>
#include <stdlib.h>
#include "aviao_fila.h"

// Função para iniciarlizar a lista de aviões
void inicializa(Fila* f){
    f->inicio = NULL;
    f->fim = NULL;
}

// Função para reinicializar a lista de aviões
void reinicializar(Fila* f){
    Elemento* apagar;
    Elemento* i = f->inicio;

    while(i != NULL){
        apagar = i;
        i = i->prox;
        free(apagar);
    }
    f->inicio = NULL;
}

// Função para verificar quantos aviões estão na fila de espera
int qtd_avioes(Fila *f){
    Elemento* i = f->inicio;
    int qtd;
    while(i != NULL){
        qtd++;
        i = f->inicio->prox;
    }
    return qtd;
}

// Função para autorizar a decolagem do primeiro avião da fila
int liberar_aviao(Fila *f){
    if(f->inicio == NULL){
        return 0;
    }

    Elemento* i = f->inicio;
    f->inicio = f->inicio->prox;
    free(i);
    return 1;
}

// Adicionar avião à lista de espera
int inserir_aviao(Fila *fila, Aviao novo){
    Elemento* i;
    i = malloc(sizeof(Elemento));
    if( i == NULL){
        return 0;
    }

    i->avi = novo;
    i->prox = NULL;
    if(fila->inicio == NULL){
        fila->inicio = i;
    }else{
        fila->fim->prox = i;
    }
    fila->fim = i;
    return 1;
}

// Listar todos os aviões da fila de espera
void listar_avioes(Fila *f){
    Elemento* i = f->inicio;
    while(i != NULL){
        printf("\nNome do aviao: %s", i->avi.nome);
        printf("\nIdentificador do aviao: %d",i->avi.identificador);
        printf("\n---------------------------\n");
        i = i->prox;
    }
}

// Acessar o primeiro elemento da fila
Elemento *primeiro_elemento(Fila* f){
    return (f->inicio);
}

// Listar as características do primero avião da fila
void primeiro_aviao(Fila* f){
    Elemento*i = f->inicio;
    if(i == primeiro_elemento(f)){
        printf("\nNome do primeiro aviao: %s", i->avi.nome);
        printf("\nIdentificador do primeiro aviao: %d", i->avi.identificador);
    }
}

