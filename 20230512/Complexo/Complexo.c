#include <stdio.h>
#include <stdlib.h>

#include "Complexo.h"

Complexo *criar(float x, float y){
    Complexo *out = malloc(sizeof(Complexo));
    out->real = x;
    out->imag = y;

    printf("\n Numero complexo: %.1f + %.1fi",x, y);
    return out;
}

void destruir(Complexo *n1, Complexo *n2){
    free(n1);
    free(n2);
}

void somar(Complexo *n1, Complexo *n2){ 
    printf("\nA soma eh %.1f + %.1fi",n1->real + n2->real, n1->imag + n2->imag);
}

void subtrair(Complexo *n1, Complexo *n2){

    printf("\nA subtracao eh %.1f + %.1fi", n1->real - n2->real, n1->imag - n2->imag);
}

void multiplicar(Complexo *n1, Complexo *n2){
    printf("\nA multiplicacao eh %.1f + %.1fi", (((n1->real * n2->real) - (n1->imag * n2->imag))), ((n1->real * n2->imag) + (n1->imag * n2->real)));
}

void dividir(Complexo *n1, Complexo*n2){
    
    float div = ((n1->real*n2->real) + (n1->imag*n2->imag) / (n2->real*n2->real) + (n2->imag*n2->imag));
    float div2 = ((n1->imag*n2->real) - (n1->real*n2->imag) / (n2->real*n2->real) + (n2->imag*n2->imag));
    printf("\nA diviao eh %.1f + %.1fi",div, div2);
}

void linha(){
    printf("\n---------------------------\n");
}