#ifndef AULA_H_INCLUDE
#define AULA_H_INCLUDE

typedef struct TreeNode {
    int values[2];
    struct TreeNode* children[3];
    int num_values;
}TreeNode;

// Função para criar um nó
TreeNode* create_node(int value);

// Função para inserir o valor em um nó
void insert_in_node(TreeNode* node, int value);

// Função para dividir os nós
void split_node(TreeNode* parent, int index);


#endif