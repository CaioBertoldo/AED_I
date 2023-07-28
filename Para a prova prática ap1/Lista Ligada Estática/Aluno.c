#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

// função para criar a lista de alunos
void criar(Lista *list){
    for(int i = 0; i < max - 1; i++){
        list->turma[i].next = i+1;
    }
    list->turma[max - 1].next = -1;
    list->inicio = -1;
    list->disponivel = 0;
}

// verificar o tamanho da lista
int tamanho_lista(Lista *list){
    int size = 0;
    int i = list->inicio;
    while(i != -1){
        size++;
        i = list->turma[i].next;
    }
    return size;
}

// Função para verificar espaço disponível
int obterNo(Lista *list){
    int disp = list->disponivel;
    if(list->disponivel != -1){
        list->disponivel = list->turma[disp].next;
    }
    return disp;
}

// Inserir alunos sem importar a ordem
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
    if((i != -1) && (new.code == list->turma[pos_inserir].al.code)){
        return 0;
    }

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

//Inserir alunos de forma ordenada
int inserir_aluno_ord(Lista *list, Aluno new){
     if(list->disponivel == -1){
        return 0;
    }
    int i = list->inicio;
    int pos_inserir = -1;
    while((i != -1) && new.code > list->turma[i].al.code){
        pos_inserir = i;
        i = list->turma[i].next;
    }
    if((i != -1) && (new.code == list->turma[pos_inserir].al.code)){
        return 0;
    }

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

// Função para buscar aluno
int busca(Lista *list, int num){
    int i = list->inicio;
    while(i != -1 && list->turma[i].al.code < num){
        i = list->turma[i].next;
    }
    if(i != -1 && list->turma[i].al.code == num){
        return i;
    }else{
        return -1;
    }
}

// Função para definir que o espaço do elemento que será excluido vai ficar disponível
void alocarNo(Lista *list, int i){
    list->turma[i].next = list->disponivel;
    list->disponivel = i;
}

// Função para excluir aluno pelo valor
int excluir_aluno(Lista *list, int num){
    int i = list->inicio;
    int anterior = -1;

    if(busca(list,num) == -1){
        return 0;
    }

    while(i != -1 && list->turma[i].al.code < num){
        anterior = i;
        i = list->turma[i].next;
    }
    if(anterior == -1){
        list->inicio = list->turma[i].next;
    }else{
        list->turma[anterior].next = list->turma[i].next;
    }
    alocarNo(list, i);
    return 1;
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
