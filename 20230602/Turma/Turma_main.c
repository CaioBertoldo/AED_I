#include <stdio.h>
#include <stdlib.h>

#include "Turma.h"

int main(){
    Lista class;
    start_list(&class);

    Aluno al1;
    al1.code = 123;
    al1.idade = 19;
    al1.nome = "Caio";
    insert_student(&class, al1);
    printf("\n");

    Aluno al2;
    al2.code = 356;
    al2.idade = 21;
    al2.nome = "Guilherme";
    insert_student(&class, al2);
    printf("\n");

    Aluno al3;
    al3.code = 284;
    al3.idade = 17;
    al3.nome = "Diogo";
    insert_student(&class, al3);
    printf("\n");

    printf("\n---- LISTA ----\n");
    print_elements(&class);

    printf("\n---- DELETAR ALUNO E MOSTRAR A NOVA LISTA ----\n");
    delete_student(&class, 284);
    print_elements(&class);

    printf("\n---- ALTERAR O CODIGO DE UM ALUNO ----\n");
    altera_cod(&class, 123, 400);
    print_elements(&class);
    return 0;
}
