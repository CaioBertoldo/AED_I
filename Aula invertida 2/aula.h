#ifndef AULA_H_INCLUDE
#define AULA_H_INCLUDE

// Estrutura de um nó da árvore 2-3
typedef struct Node {
    int keys[2]; // Array de chaves
    struct Node* children[3]; // Array de filhos
    int numKeys; // Número de chaves no nó
} Node;

// Função para criar um novo nó
Node* createNode(int key);

// Função para inserir uma chave na árvore
Node* insert(Node* root, int key);

// Função para imprimir a árvore
void printTree(Node* root, int level);

// Função para buscar uma chave na árvore
int search(Node* root, int key);

// Função auxiliar para encontrar o índice de uma chave em um nó
int findIndex(Node* node, int key);

// Função auxiliar para mesclar dois nós
Node* mergeNodes(Node* left, Node* right);

// Função auxiliar para reequilibrar um nó com um nó irmão
Node* balanceNodes(Node* parent, Node* node, int index);

// Função para excluir uma chave da árvore
Node* deleteKey(Node* root, int key);



#endif