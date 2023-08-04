#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    TREE a;
    initialize_tree(&a);

    // 1,2,3,4,5,6,7,15,14,13,12,11,10,9,8 
    add_AVL(&a, 1);
    add_AVL(&a, 2);
    add_AVL(&a, 3);
    add_AVL(&a, 4);
    add_AVL(&a, 5);
    add_AVL(&a, 6);
    add_AVL(&a, 7);
    add_AVL(&a, 15);
    add_AVL(&a, 14);
    add_AVL(&a, 13);
    add_AVL(&a, 12);
    add_AVL(&a, 11);
    add_AVL(&a, 10);
    add_AVL(&a, 9);
    add_AVL(&a, 8);

    printf("\nArvore in ordem: ");
    print_tree(&a);

    printf("\nArvore em pre ordem: ");
    print_tree_pre(&a);

    printf("\nÁrovre em pos orem: ");
    print_tree_pos(&a);
    return 0;
}
