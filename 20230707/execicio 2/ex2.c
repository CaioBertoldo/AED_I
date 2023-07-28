#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

// Incicializar a tabela hash
void incicializa_hash(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        tabela[i] = NULL;
    }
}

// Função de dispersão (onde vai inserir o paciente na tabela)
int dispersao(int codigo_paciente){
    return (codigo_paciente % MAX);
}

// Inserir elementos na lista
int inserir(TB_HASH tabela, PACIENTE paciente){
    int h = dispersao(paciente.cod_pac);
    ELEMENTO* anterior = NULL;
    ELEMENTO* i = tabela[h];
    while(i != NULL){
        if(i->pac.cod_pac == paciente.cod_pac){
            return 0;
        }
        anterior = i;
        i = i->proximo;
    }
    if(i == NULL){
        i = malloc(sizeof(ELEMENTO));
        i->pac = paciente;
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
            printf("\nPaciente %d", i);
            while( e != NULL){
                printf("\nNome: %s \n", e->pac.nome);
                e = e->proximo;
            }
        }
    }
}
