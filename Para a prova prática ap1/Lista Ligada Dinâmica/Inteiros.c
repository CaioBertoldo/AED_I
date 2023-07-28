#include <stdio.h>
#include <stdlib.h>
#include "Inteiros.h"

// Função para inicializar a lista
void criar(Lista *list){
    list->inicio = NULL;
}

// Função para retornar o tamanho da lista
int tamanho(Lista *list){
    int size=0;
    Elemento *i = list->inicio;
    while(i != NULL){
        size++;
        i = i->next;
    }
    return size;
}

//Busca sequencial
Elemento* busca_sequencial(Lista *list, int num){
    Elemento *i = list->inicio;
    while(i != NULL){
        if(i->num == num){
            return i;
        }
        i = i->next;
    }
    return NULL;
}

//Busca sequencial ordenada
Elemento* busca_sequencial_ord(Lista *list, int num){
    Elemento *i = list->inicio;
    while(i != NULL && i->num < num){
        i = i->next;
        if(i != NULL && i->num == num){
            return i;
        }
    }
    return NULL;
}

//Função auxiliar para inserir elementos na lista, sem ordenar
Elemento* busca_elemento_pred(Lista *list, int num, Elemento **pred){
    *pred = NULL;
    Elemento *atual = list->inicio;
    while(atual != NULL){
        *pred = atual;
        atual = atual->next;
    }
    if((atual != NULL) && (atual->num == num)){
        return atual;
    }
    return NULL;
}

//Função para inserir elementos na lista, sem ordenar
int inserir_elemento(Lista *list, int num){
    int number = num;
    Elemento* pred;
    Elemento *i;
    i = busca_elemento_pred(list, number, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(Elemento));
    i->num = num;
    if(pred == NULL){
        i->next = list->inicio;
        list->inicio = i;
    }else{
        i->next = pred->next;
        pred->next = i;
    }
    return 1;
}

//Função auxiliar para inserir elementos na lista de forma ordenada
Elemento* busca_elemento_pred_ord(Lista *list, int num, Elemento **pred){
    *pred = NULL;
    Elemento *atual = list->inicio;
    while((atual != NULL) && (atual->num < num)){
        *pred = atual;
        atual = atual->next;
    }
    if((atual != NULL) && (atual->num == num)){
        return atual;
    }
    return NULL;
}

// Função de inserir ordenado
int inserir_elemento_ord(Lista *list, int num){
    int number = num;
    Elemento* pred;
    Elemento *i;
    i = busca_elemento_pred_ord(list, number, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(Elemento));
    i->num = num;
    if(pred == NULL){
        i->next = list->inicio;
        list->inicio = i;
    }else{
        i->next = pred->next;
        pred->next = i;
    }
    return 1;
}

//Exluir um elemento da lista
int excluir_elemento(Lista *list, int num){
    Elemento *pred;
    Elemento *i;
    i = busca_elemento_pred_ord(list, num, &pred);
    if(i == NULL){
        return 0;
    }
    if(pred == NULL){
        list->inicio = i->next;
    }else{
        pred->next = i->next;
    }
    free(i);
    return 1;
}

//Função de reinicializar a lista
void reinicializar(Lista *list){
    Elemento* apagar;
    Elemento* elem = list->inicio;
    while(elem != NULL){
        Elemento* apagar = elem;
        elem = elem->next;
        free(apagar);
    }
    list->inicio = NULL;
}

//Imprimir os elementos da lista
void imprimir_lista(Lista *list){
    Elemento* i = list->inicio;
    while(i != NULL){
        printf("\nElemento %d", i->num);
        i = i->next;
    }
}
