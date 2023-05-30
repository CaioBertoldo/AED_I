#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aluno.h"

int main(){
    Turma *class;
    class = create(5);

    insert_students(class);

    printf("\n---- BUSCAR UM ALUNO PELO CODIGO E MOSTRAR SEUS DADOS ----\n");
    int cod;
    printf("\nCodigo do aluno que voce quer buscar: ");
    scanf("%d", &cod);
    sequential_search(class, cod);

    printf("\n---- BUSCAR UM ALUNO PELO CODIGO COM BUSCA BINARIA RECURSIVA ----\n");
    int cod2;
    printf("\nCodigo do aluno que voce quer buscar: ");
    scanf("%d", &cod2);
    printf("\nAluno na posicao %d", binary_search_recursive(class, cod2, 0, 4));

    printf("\n---- IMPRIMIR O CODIGO E O NOME DOS ALUNOS DA TURMA ----\n");
    print_class(class);

    release(class);
    return 0;
}
