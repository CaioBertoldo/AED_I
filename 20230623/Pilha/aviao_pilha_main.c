#include <stdio.h>
#include <stdlib.h>
#include "aviao_pilha.h"

int main(){
    Pilha pi;
    incicializa(&pi);

    Aviao a1;
    a1.nome = "Tam";
    a1.identificador = 123;
    inserir_aviao(&pi, a1);

    Aviao a2;
    a2.nome = "Gol";
    a2.identificador = 456;
    inserir_aviao(&pi, a2);

    Aviao a3;
    a3.nome = "Azul";
    a3.identificador = 789;
    inserir_aviao(&pi, a3);

    Aviao a4;
    a4.nome = "Kayak";
    a4.identificador = 965;
    inserir_aviao(&pi, a4);

    Listar_avioes(&pi);
    printf("\n\n");

    printf("\nQuantidade de avioes no hangar: %d", numero_avioes(&pi));
    printf("\n\n");

    decolar(&pi);
    printf("\nApos o aviao do topo da pilha ter decolado, restam: ");
    Listar_avioes(&pi);
    printf("\n\n");

    printf("\nPrimeiro aviao da pilha: ");
    primeiro_aviao(&pi);
    printf("\n\n");

    printf("\nNova lista: ");
    excluir_pos(&pi, 1);
    Listar_avioes(&pi);
    printf("\n\n");

    reinicializar(&pi);
    return 0;
}
