#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

// Função para inicializar a lista
void start_list(Lista *list){
    int i;
    for(i = 0; i < MAX; i++){
        list->list_elem[i].next = i+1;
    }
    list->list_elem[MAX-1].next;
    list->start = -1;
    list->available = 0;
}

// Função para achar a posição disponível
int obetrNo(Lista *list){
    int disp = list->available;
    if(list->available != -1){
        list->available = list->list_elem[disp].next;
    }
    return disp;
}

// Função para inserir elementos na lista
int insert_elements(Lista *list, int new_element){
    if(list->available == -1){
        return 0;
    }
    
    int i = list->start;
    int pos_insert = -1;
    while((i != -1) && new_element > list->list_elem[i].element){
        pos_insert = i;
        i = list->list_elem[i].next;
    }

    if((i != -1) && new_element == list->list_elem[pos_insert].element){
        return 0;
    }

    i = obetrNo(list);
    list->list_elem[i].element = new_element;
    if(pos_insert == -1){
        list->list_elem[i].next = list->start;
        list->start = i;
    } else{
        list->list_elem[i].next = list->list_elem[pos_insert].next;
        list->list_elem[pos_insert].next = i;
    }
}

int size_list(Lista *list){
    int size = 0;
    int i = list->start;
    while(i != -1){
        size++;
        i = list->list_elem[i].next;
    }
    return size;
}

void print_list(Lista *list){
    int i;
    for(i = 0; i < size_list(list); i++){
        printf("\nElemento %d: %d", i, list->list_elem[i].element);
    }
}

int letra_a(Lista *list){
    int pos_element = -1;
    int i;
    int l1[MAX];
    int indice_ultimo;

    for(i = 0; i < size_list(list); i++){
        l1[i] = list->list_elem[i].element;
    }

    for(i = 0; i < size_list(list); i++){
        indice_ultimo = i;
    }

    
    printf("\nIndice do ultimo elemento: %d", indice_ultimo);

    l1[indice_ultimo] = l1[0];
    l1[0] = l1[1];
    l1[1] = l1[2];
    l1[2] = l1[3];

    printf("\nLista l1: ");
    for(i = 0; i < size_list(list); i++){
        printf("\n Lista l1 %d: %d", i, l1[i]);
    }
}