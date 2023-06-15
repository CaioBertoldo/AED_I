#include <stdio.h>
#include <stdlib.h>

#include "Polinomio.h"

int main(){
    Polinomio p1;
    start_polinomio(&p1);

    Polinomio p2;
    start_polinomio(&p2);
    
    // Montar o polinomio p1
    insert_polinomio(&p1, 3, 5);
    insert_polinomio(&p1, 4, 9);
    insert_polinomio(&p1, 2, 4);
    insert_polinomio(&p1, 1, 5);
    insert_polinomio(&p1, 0, 7);

    printf("\n---- POLINOMIO P1 ----\n");
    print_polinomio(&p1);

    //Montar o polinomio p2
    insert_polinomio(&p2, 4, 8);
    insert_polinomio(&p2, 3, 2);
    insert_polinomio(&p2, 2, 5);
    insert_polinomio(&p2, 1, 3);
    insert_polinomio(&p2, 0, 4);

    printf("\n---- POLINOMIO P2 ----\n");
    print_polinomio(&p2);

    Polinomio p3;
    start_polinomio(&p3);

    sum_polinomio(&p1, &p2, &p3);
    printf("\n---- SOMA DE P1 E P2 ----\n");
    print_polinomio(&p3);

    restart(&p1);
    restart(&p2);
    restart(&p3);
    return 0;
}