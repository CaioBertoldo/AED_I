#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

int main(){
    Tree a;
    create_tree(&a);

    insert_tree(&a, '2');
    insert_tree(&a, '+');
    insert_tree(&a, '3');
    insert_tree(&a, '*');
    insert_tree(&a, '5');

    printf("\nInfixa: ");
    print_tree_infx(&a);

    printf("\nPrefixa: ");
    print_tree_prfx(&a);

    printf("\nPosfixa: ");
    print_tree_psfx(&a);
    return 0;
}
