#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
    TB_HASH tabela;
    inicializa_hash(tabela);

    Paciente p1;
    p1.cod_pac = 123;
    p1.nome = "Caio";
    p1.cpf = "058.525.702-73";
    p1.idade = 19;
    inserir(tabela, p1);

    Paciente p2;
    p2.cod_pac = 456;
    p2.nome = "Danilo";
    p2.cpf = "445.422.582-34";
    p2.idade = 19;
    inserir(tabela, p2);

    Paciente p3;
    p3.cod_pac = 789;
    p3.nome = "Rodolfo";
    p3.cpf = "785.632.456-98";
    p3.idade = 20;
    inserir(tabela, p3);

    Paciente p4;
    p4.cod_pac = 421;
    p4.nome = "Leonardo";
    p4.cpf = "463.654.784-45";
    p4.idade = 19;
    inserir(tabela, p4);
    
    apagar(tabela, 421);
    imprimir_hash(tabela);

    return 0;
}
