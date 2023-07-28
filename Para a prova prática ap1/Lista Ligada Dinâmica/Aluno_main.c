#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

int main(){
    Lista *list;
    criar(list);

    Aluno al1;
    al1.code = 1;
    al1.idade = 19;
    al1.nome = "Caio";
    al1.num_filhos = 0;
    inserir_aluno(list, al1);

    Aluno al2;
    al2.code = 2;
    al2.idade = 20;
    al2.nome = "Lilian";
    al2.num_filhos = 2;
    inserir_aluno(list, al2);

    imprimir_lista(list);

    excluir_aluno(list, 2);
    imprimir_lista(list);
    restart(list);
}