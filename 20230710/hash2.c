#include <stdio.h>
#include <stdlib.h>
#include "hash2.h"

// Inicializar a tabela
void inicializa_hash(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        tabela[i] = NULL;
    }
}

// Função de dispersão (sondagem linear)
int dispersao_a(int k, int i){
    return ((k + i) % MAX);
}

// Funçao de dispersão (sondagem quadrática)
int dispersao_b(int k, int i){
    return ((k + (i*i)) % MAX);
}

// Funçao de dispersão (sondagem quadrática 2)
int dispersao_c(int k, int i){
    return ((k + 2*i + (i*i)) % MAX);
}

// Função de dispersão (normal, para usar com hash duplo)
int dispersao(int k){
    return (k % MAX);
}

// Função de dispersão (hash duplo)
int dispersao_d(int k){
    return (7 - (k % 7));
}

// Inserir elemento com posição consecutiva livre
int inserir(TB_HASH tabela, int n){
    int i = 0;
    int h = dispersao(n);
    while(tabela[h] != NULL){
        if(tabela[h]->num == n){
            return 0;
        }
        i++;
        h = dispersao_a(n, i);
    }
    dispersao_d(n);
    printf("\nTotal: %d", i);

    if(tabela[h] == NULL){ // se não encontrou o paciente
        tabela[h] = malloc(sizeof(NUMERO));
        tabela[h]->num = n;
    }else{
        h++;
        while(tabela[h] != NULL){
            h++;
        }
        tabela[h] = malloc(sizeof(NUMERO));
        tabela[h]->num = n;
    }
    return 1;
}

// Imprimir a tabela hash
void imprimmir(TB_HASH tabela){
    int i;
    for(i = 0; i < MAX; i++){
        if(tabela[i] != NULL){
            printf("\nModulo: %d", i);
            printf("\n N --> %d\n", tabela[i]->num);
        }
    }
}