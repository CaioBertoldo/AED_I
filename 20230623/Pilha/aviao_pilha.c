#include <stdio.h>
#include <stdlib.h>
#include "aviao_pilha.h"

// Inicializar a pilha de aviões
void incicializa(Pilha* p){
    p->topo = NULL;
}

// Reicicializar a pilha
void reinicializar(Pilha* p){
    Elemento* apagar;
    Elemento* i = p->topo;

    while(i != NULL){
        apagar = i;
        i = i->prox;
        free(apagar);
    }
    p->topo = NULL;
}

// Listar o número de aviões aguardando no hangar
int numero_avioes(Pilha* p){
    Elemento* i = p->topo;
    int cont = 0;
    while(i != NULL){
        cont++;
        i = i->prox;
    }
    return cont;
}

// Tirar o avião do hangar
int decolar(Pilha *p){
    if(p->topo == NULL){
        return 0;
    }
    Elemento* i = p->topo;
    p->topo = p->topo->prox;
    free(i);
    return 1;
}

// Adicionar um avião no hangar
int inserir_aviao(Pilha* p, Aviao novo){
    Elemento* i;
    i = malloc(sizeof(Elemento));
    if(i==NULL){
        return 0;
    }
    i->avi = novo;
    i->prox = p->topo;
    p->topo = i;
    return 1;
}

// Listar os aviões que estão no hangar
void Listar_avioes(Pilha* p){
    Elemento*i = p->topo;
    while(i != NULL){
        printf("\nNome do aviao: %s", i->avi.nome);
        printf("\nIdentificador do aviao: %d", i->avi.identificador);
        printf("\n---------------------\n");
        i = i->prox;
    }
}

// Acessar o primeiro elemento da pilha
Elemento* primeiro_elemento(Pilha* p){
    return (p->topo);
}

// Listar os dados do primeiro avião
void primeiro_aviao(Pilha *p){
    Elemento*i = p->topo;
    if(i == primeiro_elemento(p)){
        printf("\nNome do primeiro: %s", i->avi.nome);
        printf("\nIdentificador do primeiro aviao: %d", i->avi.identificador);
    }
}

// Tirar um aviao do hangar pela posição
int excluir_pos(Pilha* p, int pos){
    int i;
    Pilha *p2 = malloc(sizeof(Pilha));
    incicializa(p2);
    for(i = 0; i < pos; i++){
        inserir_aviao(p2, p->topo->avi);
        decolar(p);
    }
    decolar(p);

    while(p2->topo != NULL){
        inserir_aviao(p, p2->topo->avi);
        decolar(p2);
    }
    free(p2);
}
