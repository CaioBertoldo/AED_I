#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


// Função para inicializar uma árvore
void initialize_tree(TREE* a){
    a->root = NULL;
}

// Função para criar um nó
NODE* create_node(int n){
    NODE* new_node = malloc(sizeof(NODE));
    new_node->num = n;
    new_node->h = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Verificar o máximo
int max(int v1, int v2){
    if(v1  > v2){
        return v1;
    } else{
        return v2;
    }
}

// Função para achar a altura de cada nó
int height(NODE* root){
    if(!root){
        return -1;
    } else{
        return root->h;
    }
}

// Função para fazer rotações-direita
NODE* rot_right(NODE* no_desb){
<<<<<<< HEAD
    NODE* aux = malloc(sizeof(NODE));
=======
    NODE* aux;
>>>>>>> d283f3e46f01e0bc2a1d07b6b30259ba280dbbe4
    aux = no_desb->left;
    no_desb->left = aux->right;
    aux->right = no_desb;

    no_desb->h = max(height(no_desb->right), height(no_desb->left)) + 1;

    aux->h = max(height(aux->left), height(no_desb)) + 1;
    return aux;
}

// Função para fazer rotações-esquerda
NODE* rot_left(NODE* no_desb){
<<<<<<< HEAD
    NODE* aux = malloc(sizeof(NODE));
=======
    NODE* aux;
>>>>>>> d283f3e46f01e0bc2a1d07b6b30259ba280dbbe4
    aux = no_desb->right;
    no_desb->right = aux->left;
    aux->left = no_desb;

    no_desb->h = max(height(no_desb->right), height(no_desb->left)) + 1;

    aux->h = max(height(aux->right), height(no_desb)) + 1;
    return aux;
}

// Rotação dupla (esquerda-direita)
NODE* rot_left_right(NODE* no_desb){
    no_desb->left = rot_left(no_desb->left);
    return rot_right(no_desb);
}

// Rotação dupla (direita-esquerda)
NODE* rot_right_left(NODE* no_desb){
    no_desb->right = rot_right(no_desb->right);
    return rot_left(no_desb);
}

// Inserir o nó
NODE* insert_AVL(NODE* root, NODE* node){
    if(root == NULL){
        return node;
    }
    if(root->num > node->num){
        root->left = insert_AVL(root->left, node);
        if((height(root->right) - height(root->left))  == 2){
            if(node->num < root->left->num){
                root = rot_right(root);
            }else{
                root = rot_left_right(root);
            }
        }
    } else{
        if(root->num < node->num){
            root->right = insert_AVL(root->right, node);
            if((height(root->right) - height(root->left)) == 2){
                if(node->num > root->right->num){
                    root = rot_left(root);
                } else{
                    root = rot_right_left(root);
                }
            }
        }
    }
    root->h = max(height(root->left), height(root->right)) + 1;
    return root;
}

// Adicionar na árvore
int add_AVL(TREE* a, int n){
    NODE* new_node = malloc(sizeof(NODE));
    new_node->num = n;
    new_node->h = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    a->root = insert_AVL(a->root, new_node);
    return 1;
}

// Percorrer a árvore in ordem
void in_ord(NODE* root){
    if(!root){
        return;
    }
    in_ord(root->left);
    printf("%d ", root->num);
    in_ord(root->right);
}

// Imprimir a árvore in ordem
void print_tree(TREE* a){
    return in_ord(a->root);
}

// Percorrer a árvore em pré ordem
void pre_ord(NODE* root){
    if(!root){
        return;
    }
    printf("%d ", root->num);
    pre_ord(root->left);
    pre_ord(root->right);
}

// Imprimir a árvore em pré ordem
void print_tree_pre(TREE* a){
    return pre_ord(a->root);
}

// Percorrer a árvore em pós ordem
void pos_ord(NODE* root){
    if(!root){
        return;
    }
    pos_ord(root->left);
    pos_ord(root->right);
    printf("%d ", root->num);
}

// Imprimir a árvore em pós ordem
void print_tree_pos(TREE* a){
    return pos_ord(a->root);
}