#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prova.h"

int main(){
    time_t now;
    time(&now);
    printf("\nCaio Bertoldo Bezerra");
    printf("\nNumero do exercicio: 005");
    printf("\nData e hora de entrega %s", ctime(&now));

    Deque d1;
    inicializa(&d1);
    inserir(&d1, 1);
    inserir(&d1, 3);
    inserir(&d1, 5);
    inserir(&d1, 7);

    Deque d2;
    inicializa(&d2);
    inserir(&d2, 2);
    inserir(&d2, 4);
    inserir(&d2, 6);
    inserir(&d2, 8);

    printf("\nDeque 1:");
    mostrar_deque(&d1);
    printf("\n");

    printf("\nDeque 2:");
    mostrar_deque(&d2);
    printf("\n");

    Deque d3;
    inicializa(&d3);
    intercalar(&d1, &d2, &d3);
    printf("\nDeque 3:");
    mostrar_deque(&d3);

    reinicializa(&d1);
    reinicializa(&d2);
    reinicializa(&d3);
    return 0;
}
