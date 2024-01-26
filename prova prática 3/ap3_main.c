#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ap3.h"

int main(){
    time_t now;
    time(&now);
    printf("\nCaio Bertoldo Bezerra");
    printf("\nData e hora de entrega %s", ctime(&now));

    /*                      6        
                     /             \ 
                  3                 10                              
               /    \            /         \ 
           1        4        8            42
             \               /          /        \                

                2         7          23       54*/

   ARVORE a;
    inicializa_arvore(&a);
    // 24, 10, 32, 5, 12, 29, 35
    
    NUMERO n;
    n.num = 6;
    NO* novo = criar_no(n);
    adiciona(&a, novo);
    

    NUMERO n2;
    n2.num = 3;
    NO* novo2 = criar_no(n2);
    adiciona(&a, novo2);

    NUMERO n3;
    n3.num = 1;
    NO* novo3 = criar_no(n3);
    adiciona(&a, novo3);

    NUMERO n4;
    n4.num = 2;
    NO* novo4 = criar_no(n4);
    adiciona(&a, novo4);

    NUMERO n5;
    n5.num = 4;
    NO* novo5 = criar_no(n5);
    adiciona(&a, novo5);

    NUMERO n6;
    n6.num = 10;
    NO* novo6 = criar_no(n6);
    adiciona(&a, novo6);

    NUMERO n7;
    n7.num = 8;
    NO* novo7 = criar_no(n7);
    adiciona(&a, novo7);

    NUMERO n8;
    n8.num = 7;
    NO* novo8 = criar_no(n8);
    adiciona(&a, novo8);

    // 42, 23, 54

    NUMERO n9;
    n9.num = 42;
    NO* novo9 = criar_no(n9);
    adiciona(&a, novo9);

    NUMERO n10;
    n10.num = 23;
    NO* novo10 = criar_no(n10);
    adiciona(&a, novo10);

    NUMERO n11;
    n11.num = 54;
    NO* novo11 = criar_no(n11);
    adiciona(&a, novo11);

    printf("\nArvore: ");
    imprimir_arvore(&a);
    linha();

    maioresa(&a, 10);
    linha();

    maioresa(&a, 3);
    linha();


}