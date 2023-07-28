#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

int main(){
    Lista *l1 = criar(4);

    l1->nome = "Caio";
    l1->code = 1;
    l1->idade = 19;
    l1->num_filhos = 0;

    imprimir_elementos(l1);
    
}