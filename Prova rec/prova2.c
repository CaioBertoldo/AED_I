#include <stdio.h>
#include <stdlib.h>
#include "prova2.h"

Lista *criar(int tam){
    Lista *out;
    out = malloc(sizeof(Lista));
    if(out != NULL){
        out->qtd = 0;
    }
    return out;
}

int inserir_elementos(Lista *list, Aluno al1){
    int i;
    if(list->qtd == max){
        return -1;
    }
    for(i = list->qtd -1; i >= 0; i--){
        list->al[i + 1].code = list->al[i].code;
        list->al[i + 1].idade = list->al[i].idade;
        list->al[i + 1].nome = list->al[i].nome;
        list->al[i + 1].num_filhos = list->al[i].num_filhos;
    }
    list->al[0].code = al1.code;
    list->al[0].nome = al1.nome;
    list->al[0].idade = al1.idade;
    list->al[0].num_filhos = al1.num_filhos;
    list->qtd++;
}

void imprimir(Lista *l){
    for(int i = 0; i < l->qtd; i++){
        printf("\nCogido do aluno: %d", l->al[i].code);
        printf("\nNome: %s", l->al[i].nome);
        printf("\nIdade: %d",l->al[i].idade);
        printf("\nNumero de filhos: %d", l->al[i].num_filhos);
    }
}

int maior_igual_idade(Lista *l, int idade){
    int mai = 0;
    int i;
    for(i = 0; i < l->qtd; i++){
        if(l->al[i].idade >= idade){
            mai++;
        }
    }
    return mai;
}


