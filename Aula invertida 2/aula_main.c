#include <stdio.h>
#include <stdlib.h>
#include "aula.h"


int main() {
    Node* root = NULL;
    
    // Inserindo chaves na árvore
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 15);
    root = insert(root, 25);
<<<<<<< HEAD
    root = insert(root, 36);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 41);
=======
>>>>>>> d283f3e46f01e0bc2a1d07b6b30259ba280dbbe4
    
    // Imprimindo a árvore
    printTree(root, 0);
    
    // Buscando chaves na árvore
    int keyToSearch = 15;
    if (search(root, keyToSearch)) {
        printf("Chave %d encontrada na arvore.\n", keyToSearch);
    } else {
        printf("Chave %d não encontrada na arvore.\n", keyToSearch);
    }

<<<<<<< HEAD
    deleteKey(root, 36);
=======
    deleteKey(root, 6);
>>>>>>> d283f3e46f01e0bc2a1d07b6b30259ba280dbbe4

    printTree(root, 0);

    return 0;
}