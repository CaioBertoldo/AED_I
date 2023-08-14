#include <stdio.h>
#include <stdlib.h>
#include "aula.h"



// Função para criar um novo nó
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    for (int i = 0; i < 3; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Função para inserir uma chave na árvore
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    
    if (root->numKeys == 1) {
        if (key < root->keys[0]) {
            root->children[0] = insert(root->children[0], key);
        } else {
            root->children[1] = insert(root->children[1], key);
        }
    } else if (root->numKeys == 2) {
        if (key < root->keys[0]) {
            root->children[0] = insert(root->children[0], key);
        } else if (key > root->keys[1]) {
            root->children[2] = insert(root->children[2], key);
        } else {
            root->children[1] = insert(root->children[1], key);
        }
    }
    
    return root;
}

// Função para imprimir a árvore
void printTree(Node* root, int level) {
    if (root != NULL) {
        if (root->numKeys == 1) {
            printf("Level %d: %d\n", level, root->keys[0]);
        } else if (root->numKeys == 2) {
            printf("Level %d: %d, %d\n", level, root->keys[0], root->keys[1]);
        }
        
        for (int i = 0; i < 3; i++) {
            printTree(root->children[i], level + 1);
        }
    }
}

// Função para buscar uma chave na árvore
int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    
    for (int i = 0; i < root->numKeys; i++) {
        if (key == root->keys[i]) {
            return 1;
        } else if (key < root->keys[i]) {
            return search(root->children[i], key);
        }
    }
    
    return search(root->children[root->numKeys], key);
}

// Função auxiliar para encontrar o índice de uma chave em um nó
int findIndex(Node* node, int key) {
    int index = 0;
    while (index < node->numKeys && key > node->keys[index]) {
        index++;
    }
    return index;
}

// Função auxiliar para mesclar dois nós
Node* mergeNodes(Node* left, Node* right) {
    left->keys[left->numKeys] = right->keys[0];
    left->children[left->numKeys + 1] = right->children[0];
    left->children[left->numKeys + 2] = right->children[1];
    left->numKeys++;

    free(right);
    return left;
}

// Função auxiliar para reequilibrar um nó com um nó irmão
Node* balanceNodes(Node* parent, Node* node, int index) {
    Node* sibling = parent->children[index == 0 ? 1 : 0];

    if (sibling->numKeys == 1) {
        // Mesclar os nós se o irmão tiver apenas uma chave
        node = mergeNodes(node, sibling);
        parent->children[index == 0 ? 1 : 0] = NULL;
        free(sibling);
    } else {
        // Reorganizar as chaves entre os nós
        if (index == 0) {
            // Rotacionar à esquerda
            node->keys[1] = parent->keys[0];
            parent->keys[0] = sibling->keys[0];
            sibling->keys[0] = sibling->keys[1];
            sibling->numKeys--;
            node->children[2] = sibling->children[1];
            sibling->children[1] = sibling->children[2];
            sibling->children[2] = NULL;
        } else {
            // Rotacionar à direita
            node->keys[1] = parent->keys[0];
            parent->keys[0] = sibling->keys[1];
            sibling->keys[1] = sibling->keys[0];
            sibling->numKeys--;
            node->children[2] = node->children[1];
            node->children[1] = sibling->children[1];
            sibling->children[1] = sibling->children[0];
            sibling->children[0] = NULL;
        }
    }

    return node;
}

// Função para excluir uma chave da árvore
Node* deleteKey(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    int index = findIndex(root, key);

    if (index < root->numKeys && key == root->keys[index]) {
        if (root->numKeys == 1) {
            // Caso 1: Nó folha com apenas uma chave
            // Neste caso, basta remover a chave do nó
            // e liberar o nó
            free(root);
            return NULL;
        } else {
            // Caso 2: Nó com mais de uma chave
            // Encontrar o predecessor da chave (máximo na subárvore esquerda)
            Node* predecessor = root->children[index];
            while (predecessor->children[2] != NULL) {
                predecessor = predecessor->children[2];
            }
            // Substituir a chave a ser excluída pelo predecessor
            root->keys[index] = predecessor->keys[1];
            // Recursivamente excluir o predecessor
            root->children[index] = deleteKey(root->children[index], predecessor->keys[1]);
        }
    } else {
        // A chave a ser excluída pode estar em um dos filhos
        if (root->numKeys == 1) {
            // Se o nó tiver apenas um filho, reequilibrar
            if (root->children[0] != NULL) {
                root = balanceNodes(root, root->children[0], 0);
            } else if (root->children[1] != NULL) {
                root = balanceNodes(root, root->children[1], 1);
            }
        }
        // Recursivamente excluir a chave nos filhos adequados
        if (index >= root->numKeys) {
            index = root->numKeys - 1;
        }
        root->children[index] = deleteKey(root->children[index], key);
    }

    return root;
}
