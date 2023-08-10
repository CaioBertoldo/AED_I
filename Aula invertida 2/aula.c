#include <stdio.h>
#include <stdlib.h>
#include "aula.h"

// Função para criar um nó
TreeNode* create_node(int value){
    TreeNode* new_node = malloc(sizeof(TreeNode));
    new_node->values[0] = value;
    new_node->num_values = 1;
    for(int i = 0; i < 3; i++){
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Função para inserir o valor em um nó
void insert_in_node(TreeNode* node, int value){
    int i = node->num_values - 1;
    while(i >= 0 && value < node->values[i]){ 
        node->values[i + 1] = node->values[i];
        i--;
    }
    node->values[i + 1] = value;
    node->num_values++;
}

// Função para dividir os nós
void split_node(TreeNode* parent, int index){
    TreeNode* new_node = create_node(parent->values[1]);
    new_node->children[0] = parent->children[2];
    parent->children[2] = NULL;

    if(index == 0){
        new_node->children[1] = parent->children[1];
        parent->children[1] = NULL;
        insert_in_node(parent, parent->children[1]->values[1]);
        parent->children[0]->num_values = 1;
    } else{
        insert_in_node(parent, parent->children[1]->values[1]);
        parent->children[1]->num_values = 1;
    }
    parent->children[index] = new_node;
}

// Função para inserir valor
void insert_Value(TreeNode** root, int value){
    if(*root == NULL){ // se a raiz for nula
        *root = create_node(value);
    } else {
        if((*root)->num_values ==  1){
            if(value < (*root)->values[0]){
                insert_Value(&(*root)->children[0], value);
            } else {
                insert_Value(&(*root)->children[1], value);
            }
        } else {
            insert_Value(&(*root)->children[1], value);
        }
    } else {
        if(value < (*root)->values[0]){
            insert_Value(&(*root)->)
        }
    }
}