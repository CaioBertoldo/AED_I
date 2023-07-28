#include <stdio.h>
#include <stdlib.h>

#include "Lista_inteiros.h"

// Função para criar a lista
LISTA *criar(int size){
    LISTA *out;
    out = malloc(sizeof(LISTA));
    out->vector = malloc(size * sizeof(int));
    out->qtd = 0;
    return out;
}


// Função para verificar se a lista está cheia
int lista_cheia(LISTA *list){
    if(list == NULL){
        return -1;
    }else{
        return (list->qtd == max);
    }
}

// Função para verficar se a lista está vazia
int lista_vazia(LISTA *list){
    if(list == NULL){
        return -1;
    }else{
        return (list->qtd == 0);
    }
}

// Função para inserir elemento no início da lista, sem importar a ordem
int inserir_elementos(LISTA *list, int num){
    int i;
    if(lista_cheia(list) ==  max){
        return -1;
    }
    for(i = list->qtd -1; i >= 0; i--){
        list->vector[i + 1] = list->vector[i];
    }
    list->vector[0] = num;
    list->qtd++;
}

// FunÇÃO de busca sequencial
int busca_sequencial(LISTA *list, int valor){
    int i;
    for(i = 0; i < list->qtd; i++){
        if(list->vector[i] == valor){
            return i; //ou i+1
        }
    }
    return -1;
}

// Função de busca sequencial ordenada
int busca_sequencial_ordenada(LISTA *list, int valor){
    int i = 0;
    for(i; i < list->qtd; i++){
        if(list->vector[i] >= valor){
            if(list->vector[i] == valor){
                return -1;
            }
            return i;
        }
    }
    return i;
}

// Função de busca binária
int busca_binaria(LISTA *list, int valor){
    int primeiro = 0;
    int ultimo = list->qtd-1;
    int meio = -1;
    while(primeiro <= ultimo){
        meio = primeiro + (ultimo - primeiro) / 2;
        if(valor = list->vector[meio]){
            return meio+1;
        }else if(valor > list->vector[meio]){
            primeiro = meio+1;
        }else{
            ultimo = meio-1;
        }
    }
    return -1;

}

// Função para inserir elemento na posição indicada pelo usuário
int inserir_elemento_pos(LISTA *list, int pos, int num){
    int i;
    if(lista_cheia(list) || pos > max - 1 || pos < 0){
        return -1;
    }

    for(i = list->qtd - 1; i >= pos; i--){
        list->vector[i + 1] = list->vector[i];
    }
    list->vector[pos] = num;
    list->qtd++;
}

// Função para inserir elemento de forme ordenada
int inserir_elemento_ordenado(LISTA *list, int valor){
    int result_busca;
    if(lista_cheia(list)){
        return -1;
    }
    result_busca = inserir_elemento_pos(list, busca_sequencial_ordenada(list, valor), valor);
    if(result_busca == -1){
        return -1;
    }
    return result_busca;
}

// Função que retorna o tamanho da lista
int tamanho_lista(LISTA *list){
    if(list == NULL){
        return -1;
    }else{
        return list->qtd;
    }
}

//Função de excluir um elemento pela posição
int excluir_elemento_pos(LISTA *list, int pos){
    int i;
    if(lista_vazia(list)){
        return -1;
    }
    for(i = pos-1; i < tamanho_lista(list)-1; i++){
        list->vector[i] = list->vector[i + 1];
    }
    list->qtd--;
    return 1;
}

//Função para imprimir os elementos da lista
void imprimir_lista(LISTA *list){
    int i;
    for(i = 0; i < tamanho_lista(list); i++){
        printf("\nElemento %d: %d", i, list->vector[i]);
    }
}

void liberar(LISTA *list){
    free(list);
}