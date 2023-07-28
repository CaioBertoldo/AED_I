#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

int main(){
    Deque d;
    inicializa(&d);

    Aluno al1;
    al1.nome = "Caio Bertoldo";
    al1.matricula = 123;
    inserir_aluno(&d, al1);

    Aluno al2;
    al2.nome = "Carlos Eduardo";
    al2.matricula = 456;
    inserir_aluno(&d, al2);

    Aluno al3;
    al3.nome = "Rodolfo Simoes";
    al3.matricula = 789;
    inserir_aluno(&d, al3);

    Aluno al4;
    al4.nome = "Danilo Jorge";
    al4.matricula = 987;
    inserir_aluno(&d, al4);

    Aluno al5;
    al5.nome = "Diogo Gomes";
    al5.matricula = 654;
    inserir_aluno(&d, al5);

    exibir(&d, 2, 'i');

    reinicializa(&d);
    return 0;
}