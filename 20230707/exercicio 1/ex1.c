#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

// Função para inicializar a tabela hash
void inicializa_hash(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        tabela[i] = NULL;
    }
}

// Função de dispersão (saber onde vai inserir na tabela)
int dispersao_hash(int cod_pac){
    return(cod_pac % MAX);
}

// Inserir paciente com posição consecutiva livre
int inserir(TB_HASH tabela, Paciente paciente){
    int h = dispersao_hash(paciente.cod_pac);
    while(tabela[h] != NULL){
        if(tabela[h]->cod_pac == paciente.cod_pac){
            return 0;
        }
        h = (h+1) % MAX;
    }

    if(tabela[h] == NULL){ // se não encontrou o paciente
        tabela[h] = malloc(sizeof(Paciente));
        *(tabela[h]) = paciente;
    }else{
        h++;
        while(tabela[h] != NULL){
            h++;
        }
        tabela[h] = malloc(sizeof(Paciente));
        *(tabela[h]) = paciente;
    }
    return 1;
}

// Buscar com posição consecutiva livre
Paciente* busca(TB_HASH tabela, int codigo_paciente){
    int h = dispersao_hash(codigo_paciente);
    while(tabela[h] != NULL){
        if(tabela[h]->cod_pac == codigo_paciente){
            return tabela[h];
        }
        h = (h+1) % MAX;
    }
    return NULL;
}

// Função para mostrar a tabela hash
void imprimir_hash(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        if(tabela[i] != NULL){
            printf("\nPaciente %d", i);
            printf("\nCodigo do paciente: %d", tabela[i]->cod_pac);
            printf("\nNome: %s", tabela[i]->nome);
            printf("\nCpf: %s", tabela[i]->cpf);
            printf("\nIdade: %d", tabela[i]->idade);
            printf("\n");
        }
    }
}
