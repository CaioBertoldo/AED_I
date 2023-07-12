#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

int main(){
    TB_HASH tabela;
    incicializa_hash(tabela);

    inserir(tabela, 12);
    inserir(tabela, 44);
    inserir(tabela, 13);
    inserir(tabela, 88);
    inserir(tabela, 23);
    inserir(tabela, 94);
    inserir(tabela, 11);
    inserir(tabela, 39);
    inserir(tabela, 20);
    inserir(tabela, 16);
    inserir(tabela, 5);

    imprimir_hash(tabela);
    return 0;
}