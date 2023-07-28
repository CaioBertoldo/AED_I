#include <stdio.h>
#include <stdlib.h>
#include "prova.h"
#include <time.h>


int main(){
    time_t now;
    time(&now);
    printf("\nData e hora de entrega %s", ctime(&now));
    printf("\nCaio Bertoldo Bezerra");
    printf("\nNumero do exercicio: 011");

    Lista l;
    criar(&l);

    Aluno a1;
    a1.codigo = 001;
    a1.nome = "Daniel";
    a1.idade = 21;
    a1.num_filhos = 0;
    inserir_aluno_ord(&l, a1);

    Aluno a2;
    a2.codigo = 002;
    a2.nome = "Suza";
    a2.idade = 19;
    a2.num_filhos = 0;
    inserir_aluno_ord(&l, a2);

    Aluno a3;
    a3.codigo = 003;
    a3.nome = "Danilo";
    a3.idade = 24;
    a3.num_filhos = 1;
    inserir_aluno_ord(&l, a3);

    Aluno a4;
    a4.codigo = 004;
    a4.nome = "Camila";
    a4.idade = 18;
    a4.num_filhos = 0;
    inserir_aluno_ord(&l, a4);

    Aluno a5;
    a5.codigo = 005;
    a5.nome = "Carlos";
    a5.idade = 22;
    a5.num_filhos = 1;
    inserir_aluno_ord(&l, a5);

    printf("\nAluno com menos idade: %d", menor(&l));
    imprimir_menor(&l);


}
