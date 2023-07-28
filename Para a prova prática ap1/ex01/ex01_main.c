#include <stdio.h>
#include <stdlib.h>
#include "ex01.h"

int main(){
    Lista *l1;
    inicializar(l1);

    Aluno al1;
    al1.code = 2;
    al1.idade = 7;
    al1.name = "oiiii";
    al1.num_filhos = 0;
    inserir_aluno(l1, al1);

    Aluno al2;
    al2.code = 2;
    al2.idade = 5;
    al2.name = "aaaaa";
    al2.num_filhos = 0;
    inserir_aluno(l1, al2);

    Aluno al3;
    al3.code = 6;
    al3.idade = 90;
    al3.name = "ewfdewfde";
    al3.num_filhos = 0;
    inserir_aluno(l1, al3);

    imprimir_lista(l1);

}