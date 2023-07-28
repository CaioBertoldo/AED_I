#include <stdio.h>
#include <stdlib.h>
#include "prova.h"

// função para criar a lista de alunos
void criar(Lista *list){
    for(int i = 0; i < max - 1; i++){
        list->turma[i].prox = i+1;
    }
    list->turma[max - 1].prox = -1;
    list->inicio = -1;
    list->disponivel = 0;
}

int obterNo(Lista *list){
    int disp = list->disponivel;
    if(list->disponivel != -1){
        list->disponivel = list->turma[disp].prox;
    }
    return disp;
}

int inserir_aluno_ord(Lista *class, Aluno new_aluno){
    if(class->disponivel == -1){
        return -1;
    }

    int i = class->inicio;
    int pos_insert = -1;
    while((i != -1) && new_aluno.codigo > class->turma[i].al.codigo){
        pos_insert = i;
        i = class->turma[i].prox;
    }
    
    // Verificar se existe um elemento igual na lista
    if((i != -1) && (new_aluno.codigo == class->turma[pos_insert].al.codigo)){
        return -1;
    }

    i = obterNo(class);
    class->turma[i].al = new_aluno;
    if(pos_insert == -1){
        class->turma[i].prox = class->inicio;
        class->inicio = i;
    } else{
        class->turma[i].prox = class->turma[pos_insert].prox;
        class->turma[pos_insert].prox = i;
    }
}

void imprimir(Lista *list){
    int i = list->inicio;
    int n=0;
    while(i != -1){
        printf("\nAluno %d", n+1);
        printf("\nCodigo: %d",list->turma[i].al.codigo);
        printf("\nNome: %s", list->turma[i].al.nome);
        printf("\nIdade: %d", list->turma[i].al.idade);
        printf("\nNumero de filhos: %d", list->turma[i].al.num_filhos);
        i = list->turma[i].prox;
        n++;
    }
}

int menor(Lista *l){
    int i = l->inicio;
    int men = 100;
    while(i != -1){
        if(l->turma[i].al.idade < men){
            men = l->turma[i].al.idade;
        }
        i = l->turma[i].prox;
    }
    return men;
}

void imprimir_menor(Lista *l){
    int i = l->inicio;
    while(i != -1){
        if(l->turma[i].al.idade == menor(l)){
            printf("\nCodigo: %d",l->turma[i].al.codigo);
            printf("\nNome: %s", l->turma[i].al.nome);
            printf("\nIdade: %d", l->turma[i].al.idade);
            printf("\nNumero de filhos: %d", l->turma[i].al.num_filhos);
        }  
        i = l->turma[i].prox;
    }
}
