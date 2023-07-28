#include <stdio.h>
#include <stdlib.h>
#include "rec.h"

void inicializa_fila(Fila* f){
    f->inicio = NULL;
    f->fim = NULL;
}

void reinicializar_fila(Fila* f){
    Elemento* apagar;
    Elemento* i = f->inicio;

    while(i != NULL){
        apagar = i;
        i = i->prox;
        free(apagar);
    }
    f->inicio = NULL;
}

int inserir_fila(Fila *fila, char letra){
    Elemento* i;
    i = malloc(sizeof(Elemento));
    if( i == NULL){
        return 0;
    }

    i->letra= letra;
    i->prox = NULL;
    if(fila->inicio == NULL){
        fila->inicio = i;
    }else{
        fila->fim->prox = i;
    }
    fila->fim = i;
    return 1;
}

char liberar_fila(Fila *f){
    if(f->inicio == NULL){
        return 0;
    }

    Elemento* i = f->inicio;
    f->inicio = f->inicio->prox;
    free(i);
    return i->letra;
}

void imrpimir_frase(Fila *f){
    Elemento* i = f->inicio;
    printf("\nFrase fila: \n");
    while(i != NULL){
        printf("%c ", i->letra);
        i = i->prox;
    }
}

void incicializa_pilha(Pilha* p){
    p->topo = NULL;
}

void reinicializar_pilha(Pilha* p){
    Elemento_pilha* apagar;
    Elemento_pilha* i = p->topo;

    while(i != NULL){
        apagar = i;
        i = i->prox;
        free(apagar);
    }
    p->topo = NULL;
}

int inserir_pilha(Pilha* p, char letra){
    Elemento_pilha* i;
    i = malloc(sizeof(Elemento));
    if(i==NULL){
        return 0;
    }
    i->letra_pilha = letra;
    i->prox = p->topo;
    p->topo = i;
    return 1;
}

int transferir(Fila* f, Pilha* p){
    Elemento* i = f->inicio;
    while(i != NULL){
        inserir_pilha(p, i->letra);
        i = i->prox;
    }
    return 1;
}

void imprimir_pilha(Pilha* p){
    Elemento_pilha* i = p->topo;
    printf("\nFrase pilha: \n");
    while(i != NULL){
        printf("%c ", i->letra_pilha);
        i = i->prox;
    }
}
