#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

int main(){
    TB_HASH tabela;
    incicializa_hash(tabela);

    PACIENTE p1;
    p1.cod_pac = 123;
    p1.nome = "Caio";
    inserir(tabela, p1);
    
    PACIENTE p2;
    p2.cod_pac = 456;
    p2.nome = "Rebeca";
    inserir(tabela, p2);

    PACIENTE p3;
    p3.cod_pac = 789;
    p3.nome = "Rodolfo";
    inserir(tabela, p3);

    PACIENTE p4;
    p4.cod_pac = 321;
    p4.nome = "Malu";
    inserir(tabela, p4);

    imprimir_hash(tabela);
    
    return 0;

}
