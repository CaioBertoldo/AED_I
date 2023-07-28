#include <stdio.h>
#include <stdlib.h>
#include "prova2.h"
#include <time.h>

int main(){
    time_t now;
    time(&now);
    printf("\nData e hora de entrega %s", ctime(&now));
    printf("\nCaio Bertoldo Bezerra");
    printf("\nNumero do exercicio: 013");

    Lista *l =  criar(5);

    Aluno al1;
    al1.code = 001;
    al1.nome = "Daniel";
    al1.idade = 21;
    al1.num_filhos = 0;
    inserir_elementos(l, al1);

    Aluno al2;
    al2.code = 002;
    al2.nome = "Suza";
    al2.idade = 19;
    al2.num_filhos = 0;
    inserir_elementos(l, al2);

    Aluno al3;
    al3.code = 003;
    al3.nome = "Danilo";
    al3.idade = 24;
    al3.num_filhos = 1;
    inserir_elementos(l, al3);

    Aluno al4;
    al4.code = 004;
    al4.nome = "Camila";
    al4.idade = 18;
    al4.num_filhos = 0;
    inserir_elementos(l, al4);
     
    Aluno al5;
    al5.code = 005;
    al5.nome = "Carlos";
    al5.idade = 22;
    al5.num_filhos = 1;
    inserir_elementos(l, al5);
    
    printf("\nQuantidade de alunos com idade maior ou igual a 20: %d", maior_igual_idade(l, 20));

}