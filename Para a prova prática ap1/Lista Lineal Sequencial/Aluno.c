#include <stdio.h>
#include <stdlib.h>

#include "Aluno.h"

// Inicializar a lista
Lista *criar(int size){
    Lista *out;
    out = malloc(sizeof(Lista));
    if(out != NULL){
        out->qtd = 0;
    }
    return out;
}


//Inserir aluno na lista na lista sem importar a ordem, no inicio
int inserir_elementos(Lista *list, int code){
    int i;
    if(list->qtd == max){
        return -1;
    }
    for(i = list->qtd -1; i >= 0; i--){
        list->code[i + 1] = list->code[i];
    }
    list->code[0] = code;
    list->qtd++;
}


// Busca sequencial
int busca_sequencial(Lista *list, int valor){
    int i;
    for(i = 0; i < list->qtd; i++){
        if(list->code[i] == valor){
            return i; //ou i+1
        }
    }
    return -1;
}

// Busca sequencial ordenada
int busca_sequencial_ordenada(Lista *list, int valor){
    int i;
    for(i = 0; i < list->qtd; i++){
        if(list->code[i] >= valor){
            if(list->code[i] == valor){
                return -1;
            }
            return i;
        }
    }
    return -1;
}

// Inserir aluno pela posição indicada pelo usuário
int inserir_elemento_pos(Lista *list, int pos, int num){
    int i;
    if(list->qtd == max || pos-1 > max || pos-1 < 0){
        return -1;
    }

    for(i = list->qtd -1; i >= pos-1; i--){
        list->code[i + 1] = list->code[i];
    }
    list->code[pos-1] = num;
    list->qtd++;
}

//Inserir aluno de forma ordenada
int inserir_aluno_ordenado(Lista *list, int code){
    int result_busca;
    if(list->qtd ==  max){
        return -1;
    }
    result_busca = inserir_elemento_pos(list, busca_sequencial_ordenada(list, code)+1, code);
    if(result_busca == -1){
        return -1;
    }
    return result_busca;
}

// Quantidade de elementos da lista
int tamanho_lista(Lista *list){
    if(list->qtd == NULL){
        return -1;
    }else{
        return list->qtd;
    }
}

// Busca binária de elementos da lista
int busca_binaria(Lista *list, int valor){
    int primeiro = 0;
    int ultimo = list->qtd-1;
    int meio = -1;
    while(primeiro <= ultimo){
        meio = primeiro + (ultimo - primeiro) / 2;
        if(valor = list->code[meio]){
            return meio+1;
        }else if(valor > list->code[meio]){
            primeiro = meio+1;
        }else{
            ultimo = meio-1;
        }
    }
    return -1;
}

// Excluir aluno pela posição
int excluir_aluno_pos(Lista *list, int pos){
    int i;
    if(list->qtd == NULL){
        return -1;
    }
    for(i = 0; i < tamanho_lista(list); i++){
        list->code[i] = list->code[i + 1];
    }
    list->qtd--;
    return 1;
}

//Imprimir elementos da lista
void imprimir_elementos(Lista *list){
    int i;
    for(i = 0; i < tamanho_lista(list); i++){
        printf("\nNome: %s", list->nome[i]);
        printf("\nIdade: %d",list->idade[i]);
        printf("\nCodigo de matricula: %d", list->code[i]);
        printf("\nNumero de filhos: %d",list->num_filhos[i]);
    }
}
