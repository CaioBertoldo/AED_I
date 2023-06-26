#include <stdio.h>
#include <stdlib.h>
#include "aviao_fila.h"

int main(){
    Fila f;
    inicializa(&f);

    Aviao a1;
    a1.nome = "Tam";
    a1.identificador = 123;
    inserir_aviao(&f, a1);

    Aviao a2;
    a2.nome = "Gol";
    a2.identificador = 456;
    inserir_aviao(&f, a2);

    Aviao a3;
    a3.nome = "Azul";
    a3.identificador = 789;
    inserir_aviao(&f, a3);

    listar_avioes(&f);

    printf("\nLiberar o primeiro aviao");
    liberar_aviao(&f);

    listar_avioes(&f);

    printf("\nDados do primeiro aviao\n");
    primeiro_aviao(&f);
}