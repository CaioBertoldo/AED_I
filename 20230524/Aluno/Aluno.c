#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aluno.h"

Turma *create(int num){
    Turma *out;
    out = malloc(sizeof(Turma));
    if(out != NULL){
        out->list;
        out->quantity;
    }
    return out;
}

void insert_students(Turma *a1){
    int i;

    printf("\nInformacoes dos alunos\n");

    for(i = 0; i < 5; i++){
       printf("\nInforme o nome do aluno: ");
       scanf(" %[^\n]s", &a1->list[i].name);

       printf("\nInforme a idade do aluno: ");
       scanf("%d", &a1->list[i].age);

       printf("\nInforme o codigo do aluno: ");
       scanf("%d", &a1->list[i].code);

       printf("\nInforme o coeficiente do aluno: ");
       scanf("%f", &a1->list[i].coefficient);
    }
}

void release(Turma *class){
    free(class);
}

void sequential_search(Turma *a1, int cod){
    int i;
    for(i = 0; i < 5; i++){
        if(a1->list[i].code != cod){
            printf("\nBuscando o aluno...");
        }
        if(a1->list[i].code == cod){
            printf("\nAluno encontrado. \nNome: %s \nIdade: %d \nCoeficiente %.1f", a1->list[i].name, a1->list[i].age, a1->list[i].coefficient);
            break;
        }
    }
}

int binary_search_recursive(Turma *a1, int cod, int start, int end){
    if(start > end){
        return -1;
    }
    int middle = (start + end) / 2;
    if(cod == a1->list[middle].code){
        return middle;
    }
    if(cod < a1->list[middle].code){
        binary_search_recursive(a1, cod, start, middle - 1);
    }
    else{
        binary_search_recursive(a1, cod, middle+1, end);
    }

}

void print_class(Turma *a1){
    int i;
    for(i = 0; i < 5; i++){
        printf("\nCodigo: %d \nNome: %s", a1->list[i].code, a1->list[i].name);
    }
}
