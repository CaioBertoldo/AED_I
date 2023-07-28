#include <stdio.h>
#include <stdlib.h>
#include "Inteiros.h"

// Incicializar a lista
void criar(Lista *list){
    for(int i =0; i < MAX -1; i++){
        list->enumerar[i].next = i+1;
    }
    list->enumerar[MAX - 1].next = -1;
    list->inicio = -1;
    list->disp = 0;
}

// Retornar o tamanho da lista
int tamanho_lista(Lista *list){
    int size = 0;
    int i = list->inicio;
    while(i != -1){
        size++;
        i = list->enumerar[i].next;
    }
    return size;
}


// Função para verificar espaço disponível
int obterNo(Lista *list){
    int disponivel = list->disp;
    if(list->disp != -1){
        list->disp = list->enumerar[disponivel].next;
    }
    return disponivel;
}

// Inserir elemento sem importar a ordem
int inserir_elemento(Lista *list, int num){
    if(list->disp == -1){
        return 0;
    }
    int i = list->inicio;
    int pos_inserir = -1;
    while(i != -1){
        pos_inserir = i;
        i = list->enumerar[i].next;
    }
    if((i != -1) && (num == list->enumerar[pos_inserir].num)){
        return 0;
    } 
    i = obterNo(list);
    list->enumerar[i].num = num;
    if(pos_inserir == -1){
        list->enumerar[i].next = list->inicio;
        list->inicio = i;
    }else{
        list->enumerar[i].next = list->enumerar[pos_inserir].next;
        list->enumerar[pos_inserir].next = i;
    }
}

// Inserir elemento de forma ordenada
int inserir_elemento_ord(Lista *list, int num){
     if(list->disp == -1){
        return 0;
    }
    int i = list->inicio;
    int pos_inserir = -1;
    while((i != -1) && (num > list->enumerar[i].num)){
        pos_inserir = i;
        i = list->enumerar[i].next;
    }
    if((i != -1) && (num == list->enumerar[pos_inserir].num)){
        return 0;
    } 
    i = obterNo(list);
    list->enumerar[i].num = num;
    if(pos_inserir == -1){
        list->enumerar[i].next = list->inicio;
        list->inicio = i;
    }else{
        list->enumerar[i].next = list->enumerar[pos_inserir].next;
        list->enumerar[pos_inserir].next = i;
    }
}

// Busca sequencial
int busca_sequencial(Lista *list, int num){
    int i = list->inicio;
    while(i != -1 && list->enumerar[i].num < num){
        i = list->enumerar[i].next;
    }
    if(i != -1 && list->enumerar[i].num == num){
        return i;
    }else{
        return -1;
    }
}

//Excluir elemento pelo valor
int excluir_elemento(Lista *list, int valor){
    int i = list->inicio;
    int anterior = -1;

    if(busca_sequencial(list, valor) == -1){
        return 0;
    }

    while(i != -1 && list->enumerar[i].num < valor){
        anterior = i;
        i = list->enumerar[i].next;
    }

    if(anterior == -1){
        list->inicio = list->enumerar[i].next;
    }else{
        list->enumerar[anterior].next = list->enumerar[i].next;
    }
    alocarNo(list, i);
    return 1;
}

// Função para dizer que a posição que está excluindo agora está disponível
void alocarNo(Lista *list, int i){
    list->enumerar[i].next = list->disp;
    list->disp = i;
}

//Imprimir os elementos da lista
void imprimir_lista(Lista *list){
    int i = list->inicio;
    while(i != -1){
        printf("\nElemento %d",list->enumerar[i].num);
        i = list->enumerar[i].next;
    }
}