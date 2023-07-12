#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

// Incicializar a tabela hash
void incicializa_hash(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        tabela[i] = NULL;
    }
}

// Função de dispersão (onde vai inserir o paciente na tabela)
int dispersao(int k){
    return ((2*k + 5) % MAX);
}

// Inserir elementos na lista
int inserir(TB_HASH tabela, int n){
    int h = dispersao(n);
    ELEMENTO* anterior = NULL;
    ELEMENTO* i = tabela[h];
    while(i != NULL){
        if(i->num == n){
            return 0;
        }
        anterior = i;
        i = i->proximo;
    }
    if(i == NULL){
        i = malloc(sizeof(ELEMENTO));
        i->num = n;
        i->proximo = NULL;
        if(anterior == NULL){
            tabela[h] = i;
        }else{
            anterior->proximo = i;
        }
    }
    return 1;
}

// Imprimir a tabela hash
void imprimir_hash(TB_HASH tabela){
    ELEMENTO* e;
    for(int i = 0; i < MAX; i++){
        if(tabela[i] != NULL){
            e = tabela[i];
            printf("\nNumero %d", i);
            while( e != NULL){
                printf("\nN --> %d \n", e->num);
                e = e->proximo;
            }
        }
    }
}
