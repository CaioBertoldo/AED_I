#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

int main(){

    Lista *l1;
    criar(l1);

    Aluno a1;
    a1.code = 2;
    a1.idade = 19;
    a1.nome = "Caio";
    a1.num_filhos = 0;
    inserir_aluno(l1, a1);

    Aluno a2;
    a2.code = 5;
    a2.idade = 21;
    a2.nome = "Claudio";
    a2.num_filhos = 5;
    inserir_aluno(l1, a2);

    Aluno a3;
    a3.code = 1;
    a3.idade - 13;
    a3.nome = "Isaac";
    a3.num_filhos = 10;
    inserir_aluno(l1, a3);

    imprimir_lista(l1);

    return 0;
}