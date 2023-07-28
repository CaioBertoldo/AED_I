#include <stdio.h>
#include <stdlib.h>
#include "rec.h"
#include <time.h>

int main(){
    time_t now;
    time(&now);
    printf("\nData e hora de entrega %s", ctime(&now));
    printf("\nCaio Bertoldo Bezerra");

    Fila f;
    inicializa_fila(&f);

    inserir_fila(&f, 'M');
    inserir_fila(&f, 'U');
    inserir_fila(&f, 'I');
    inserir_fila(&f, 'T');
    inserir_fila(&f, 'O');
    inserir_fila(&f, ' ');
    inserir_fila(&f, 'F');
    inserir_fila(&f, 'A');
    inserir_fila(&f, 'C');
    inserir_fila(&f, 'I');
    inserir_fila(&f, 'L');
    
    imrpimir_frase(&f);

    Pilha p;
    incicializa_pilha(&p);
    transferir(&f, &p);

    imprimir_pilha(&p);
    reinicializar_fila(&f);
    imrpimir_frase(&f);
    return 0;

}

