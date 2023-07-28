#include <stdio.h>
#include <stdlib.h>
#include "ex01.h"

void inicializar(Lista *l){
    for(int i = 0; i < max -1; i++){
        l->turma[i].prox = i+1;
    }
    l->turma[max-1].prox = -1;
    l->inicio = -1;
    l->disponivel = 0;
}

int busca_matricula(Lista *l, int cod_al){
    int i = l->inicio;
    while(i != -1 && l->turma[i].al->code < cod_al){
        i = l->turma[i].prox;
    }

    if(i != -1 && l->turma[i].al->code == cod_al){
        return i;
    }else{
        return -1;
    }
}

// Buscar espaço disponivel
int obterNo(Lista *l){
    int disp = l->disponivel;
    if(l->disponivel != -1){
        l->disponivel = l->turma[disp].prox;
    }
    return disp;
}

// Inserir alunos
int inserir_aluno(Lista *list, Aluno new){
    if(list->disponivel == -1){
        return 0;
    }
    int i = list->inicio;
    int pos_inserir = -1;
    while(i != -1){
        pos_inserir = i;
        i = list->turma[i].next;
    }
    /*if((i != -1) && (new.code == list->turma[pos_inserir].al.code)){
        return 0;
    }*/

    i = obterNo(list);
    list->turma[i].al = new;
    if(pos_inserir == -1){
        list->turma[i].next = list->inicio;
        list->inicio = i;
    }else{
        list->turma[i].next = list->turma[pos_inserir].next;
        list->turma[pos_inserir].next = i;
    }
}

// Função para imprimir a lista
void imprimir_lista(Lista *list){
    int i = list->inicio;
    while(i != -1){
        printf("\nALuno %d", i);
        printf("\nNome: %s", list->turma[i].al.nome);
        printf("\nIdade: %d", list->turma[i].al.idade);
        printf("\nCodigo de matricula: %d", list->turma[i].al.code);
        printf("\nNumero de filhos: %d", list->turma[i].al.num_filhos);
    }
}
