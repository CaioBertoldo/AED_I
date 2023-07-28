#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main(){
    Lista list;
    start_list(&list);

    Elemento a;
    a.element = 2;
    insert_elements(&list, a.element);

    Elemento b;
    b.element = 5;
    insert_elements(&list, b.element);

    Elemento c;
    c.element = 8;
    insert_elements(&list, c.element);

    Elemento d;
    d.element = 4;
    insert_elements(&list, d.element);

    printf("\n---- IMPRIMIR LISTA DA FORMA ORIGINAL ----\n");
    print_list(&list);

    letra_a(&list);

    return 0;
}