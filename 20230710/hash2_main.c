#include <stdio.h>
#include <stdlib.h>
#include "hash2.h"

int main(){
    TB_HASH tabela;
    inicializa_hash(tabela);

    inserir(tabela, 365);
    inserir(tabela, 112);
    inserir(tabela, 180);
    inserir(tabela, 213);
    inserir(tabela, 13);
    inserir(tabela, 27);

    imprimmir(tabela);
    return 0;
}