#include <stdio.h>
#include <stdlib.h>

#include "Cubo.h"

Cubo *preencher_cubo(float x){
    Cubo *out = malloc(sizeof(Cubo));
    out->medida = x;
    return out;
}

void libera(Cubo *cub){
    free(cub);
}

void retorna_dados(Cubo *ptr){
    printf("\nAltura: %.1f", ptr->medida);
    printf("\nComprimento: %.1f", ptr->medida);
    printf("\nLargura: %.1f", ptr->medida);

    float area;
    float volume;

    area =  6 * (ptr->medida * ptr->medida);
    volume = ptr->medida * ptr->medida * ptr->medida;

    printf("\nArea: %.1f", area);
    printf("\nVolume: %.1f", volume);
}
