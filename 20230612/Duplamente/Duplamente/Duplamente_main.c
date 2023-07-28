#include <stdio.h>
#include <stdlib.h>

#include "Duplamente.h"

int main(){
    Lista *L;
    start_list(L);

    insert_element(L, 3);
    insert_element(L, 2);
    insert_element(L, 9);
    insert_element(L, 5);
    int size = size_list(L);
    printf("\nTamanho da lista: %d",size);

    printf("\n---- LISTA L DESORDENADA ----\n");
    print_list(L);
    
    printf("\n----- LISTA K ORDENADA ----\n");
    insert_value_start(L);
    restart(L);
}
