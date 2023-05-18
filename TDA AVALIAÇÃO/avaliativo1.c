// Desenvolva um TAD que represente um cubo. 
// Inclua as funções de inicializações necessárias e as operações que retornem os tamanhos de cada lado, a sua área e o seu volume

#include <stdio.h>
#include <stdlib.h>

#include "Cubo.h"

int main(){
    Cubo *forma;
    forma = preencher_cubo(5.5);
    retorna_dados(forma);
    libera(forma);
}
