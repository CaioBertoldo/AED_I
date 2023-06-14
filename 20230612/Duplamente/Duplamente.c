#include <stdio.h>
#include <stdlib.h>

#include "Duplamente.h"


void start_list(Lista *list){
    list->start = NULL;
}

Node* search_element_pred(Lista *list, int num, Node **pred){
    *pred = NULL;
    Node *current = list->start;
    while(current != NULL){
        *pred = current;
        current = current->next;
    }
    if(current != NULL && current->element == num){
        return current;
    }
    return NULL;
}

int insert_element(Lista *list, int num){
    int code = num;
    Node *pred;
    Node *i;
    i = search_element_pred(list, code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(Node));
    i->element = code;
    if(pred == NULL){
        i->next = list->start;
        i->ant = NULL;
        list->start = i;
    }else if(pred->next == NULL){
        i->next = pred->next;
        i->ant = pred;
        pred->next = i;
    }
}

void print_list(Lista *list){
    Node* i = list->start;
    while(i != NULL){
        printf("\n Elemento %d", i->element);
        i = i->next;
        printf("\n");
    }
}

void restart(Lista *list){
    Node* clear;
    Node* element = list->start;
    while(element != NULL){
        Node* clear = element;
        element = element->next;
        free(clear);
    }
    list->start = NULL;
}

int size_list(Lista *list){
    Node* i = list->start;
    int size = 0;

    while(i != NULL){
        size++;
        i = i->next;
    }
    return size;
}

Node* maior(Lista *list){
    Node *i = list->start;
    Node* mai = i;
    if(i == NULL){
        return NULL;
    }

    while(i != NULL){
        if(i->element > mai->element){
            mai = i;
        }
        i = i->next;
    }
    return mai;
}

int kill(Lista *list, Node *element){
    if(element == NULL){
        return 0;
    }
    if(element->ant != NULL){
        element->ant->next = element->next;
    }else{
        list->start = element->next;
    }

    if(element->next != NULL){
        element->next->ant = element->ant;
    }
}

int insert_value_start(Lista *list){
    Lista *K;
    start_list(K);

    Node *i;
    Node *element;
    int cont=0, size;
    size = size_list(list);

    for(cont=0; cont < size; cont++){
        i = K->start;
        element = maior(list);
        kill(list, element);
        if(i == NULL){
            element->ant = NULL;
            element->next = K->start;
            K->start = element;
        }else{
            element->next = K->start;
            K->start->ant = element->next;
            K->start = element;
        }
    }
    print_list(K);
}
