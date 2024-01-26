#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ab.h"


// Função para inicializar a árvore
void create_tree(Tree* a){
    a->root = NULL;
}

// Função para criar um nó
Node* crate_node(char exp){
    Node* new_node = malloc(sizeof(Node));
    new_node->exp = exp;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para inserir nó na árvore binária
Node* insert_node(Node* root, char exp){
    if(root == NULL){
        return crate_node(exp);
    }

    if(root->left == NULL){
        root->left = insert_node(root->left, exp);
    } else{
        root->right = insert_node(root->right, exp);
    }
    return root;
}

// Função para inserir na árvore
int insert_tree(Tree* a, char new){
    a->root = insert_node(a->root, new);
    return 1;
}

// Função para percorrer a árvore em ordem (infixa)
void in_ord(Node* root){
    if(root != NULL){
        in_ord(root->left);
        printf("%c ", root->exp);
        in_ord(root->right);
    }
}

// Função para imprimir a árvore na ordem infixa
void print_tree_infx(Tree* a){
    return in_ord(a->root);
}

// Função para percorrer em pré ordem (prefixa)
void pre_ord(Node* root){
    if(root != NULL){
        printf("%c ", root->exp);
        pre_ord(root->left);
        pre_ord(root->right);
    }
}

// Função para imporimir a árvore em ordem prefixa
void print_tree_prfx(Tree* a){
    return pre_ord(a->root);
}

// Função para percorrer em pós ordem (posfixa)
void pos_ord(Node* root){
    if(root != NULL){
        pos_ord(root->left);
        pos_ord(root->right);
        printf("%c ", root->exp);
    }
}

// Função para imprimir a árvore em odem posfixa
void print_tree_psfx(Tree* a){
    return pos_ord(a->root);
}


// FUNÇÕES PARA A FILA

// Iniciializar a fila
void create_queue(Queue* f){
    f->start = NULL;
    f->end = NULL;
}

// Reinicializar a fila
void restart_queue(Queue* f){
    Element* clear;
    Element* el = f->start;
    while(el != NULL){
        clear = el;
        el = el->next;
        free(clear);
    }
    f->start = NULL;
}

// Inserir na fila
int insert_queue(Queue* f, char exp){
    Element* i = malloc(sizeof(Element));
    if(i == NULL){
        return 0;
    }
    i->exp = exp;
    i->next = NULL;
    if(f->start == NULL){
        f->start = i;
    } else{
        f->end->next = i;
    }
    f->end = i;
    return 1;
}

// Excluir da fila
int clear_queue(Queue* f){
    if(f->start == NULL){
        return 0;
    }
    Element* i = f->start;
    f->start = f->start->next;
    free(i);
    return 1;
}
