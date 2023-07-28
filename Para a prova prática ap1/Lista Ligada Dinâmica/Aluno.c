#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

//Função para inicializar a lista
void criar(Lista *list){
    list->inicio = NULL;
}


// Retornar o tamanho da lista
int tamanho(Lista *list){
    int size=0;
    Elemento* i = list->inicio;
    while(i != NULL){
        size++;
        i = i->next;
    }
    return size;
}

// Busca sequencial 
Elemento* busca_sequencial(Lista *list, int num){
    Elemento *i = list->inicio;
    while(i != NULL){
        if(i->al.code == num){
            return i;
        }
        i = i->next;
    }
    return NULL;
}

// Busca sequencial ordenada
Elemento* busca_sequencial_ord(Lista *list, int num){
    Elemento *i = list->inicio;
    while(i != NULL && i->al.code < num){
        i = i->next;
        if(i != NULL && i->al.code == num){
            return i;
        }
    }
    return NULL;
}

//Função auxiliar para inserir valores de forma não ordenada
Elemento* busca_elem_pred(Lista *list, int cod_al, Elemento **pred){
    *pred = NULL;
    Elemento* atual = list->inicio;
    while(atual != NULL){
        *pred = atual;
        atual = atual->next;
    }
    if((atual != NULL) && (atual->al.code == cod_al)){
        return atual;
    }
    return NULL;
}

//Inserir alunos de forma não ordenada
int inserir_aluno(Lista* list, Aluno new_al){
    int new_code = new_al.code;
    Elemento* pred;
    Elemento* i;
    i = busca_elem_pred(list, new_code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(Elemento));
    i->al = new_al;
    if(pred == NULL){
        i->next = list->inicio;
        list->inicio = i;
    }else{
        i->next = pred->next;
        pred->next = i;
    }
    return 1;
}

// Função auxiliar para inserir alunos de forma ordenada
Elemento* busca_elem_pred_ord(Lista *list, int cod_al, Elemento **pred){
    *pred = NULL;
    Elemento* atual = list->inicio;
    while((atual != NULL) && atual->al.code < cod_al){
        *pred = atual;
        atual = atual->next;
    }
    if((atual != NULL) && (atual->al.code == cod_al)){
        return atual;
    }
    return NULL;
}

//Inserir elementos de forma ordenada na lista
int inserir_aluno_ord(Lista* list, Aluno new_al){
    int new_code = new_al.code;
    Elemento* pred;
    Elemento* i;
    i = busca_elem_pred_ord(list, new_code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(Elemento));
    i->al = new_al;
    if(pred == NULL){
        i->next = list->inicio;
        list->inicio = i;
    }else{
        i->next = pred->next;
        pred->next = i;
    }
    return 1;
}

//Excluir aluno
int excluir_aluno(Lista* list, int cod_al){
    Elemento* pred;
    Elemento* i;
    i = busca_elem_pred_ord(list, cod_al, &pred);
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

// Reinicializar a lista
void restart(Lista *list){
    Elemento* apagar;
    Elemento* elem = list->inicio;
    while(elem != NULL){
        Elemento* apagar = elem;
        elem = elem->next;
        free(apagar);
    }
    list->inicio = NULL;
}

//imprimir a lista
void imprimir_lista(Lista *list){
    Elemento* i = list->inicio;
    int n=0;
    while(i != NULL){
        printf("\nAluno %d", n);
        printf("\nNome: %s", i->al.nome);
        printf("\nIdade: %d", i->al.idade);
        printf("\nCodigo do aluno: %d", i->al.code);
        printf("\nNumero de filhos %d", i->al.num_filhos);
        i = i->next;
        n++;
    }
}