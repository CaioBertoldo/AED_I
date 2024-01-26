#ifndef AVL_H_INCLUDE
#define AVL_H_INCLUDE

typedef struct aux{
    int num;
    struct aux* left;
    struct aux* right;
    int h; // altura do nó
}NODE;

typedef struct{
    NODE* root;
}TREE;

// Função para inicializar uma árvore
void initialize_tree(TREE* a);

// Função para criar um nó
NODE* create_node(int n);

// Verificar o máximo
int max(int v1, int v2);

// Função para achar a altura de cada nó
int height(NODE* root);

// Função para fazer rotações-direita
NODE* rot_right(NODE* no_desb);

// Função para fazer rotações-esquerda
NODE* rot_left(NODE* no_desb);

// Rotação dupla (esquerda-direita)
NODE* rot_left_right(NODE* no_desb);

// Rotação dupla (direita-esquerda)
NODE* rot_right_left(NODE* no_desb);

// Inserir o nó
NODE* insert_AVL(NODE* root, NODE* node);

// Adicionar na árvore
int add_AVL(TREE* a, int n);

// Percorrer a árvore in ordem
void in_ord(NODE* root);

// Imprimir a árvore in ordem
void print_tree(TREE* a);

// Percorrer a árvore em pré ordem
void pre_ord(NODE* root);

// Imprimir a árvore em pré ordem
void print_tree_pre(TREE* a);

// Percorrer a árvore em pós ordem
void pos_ord(NODE* root);

// Imprimir a árvore em pós ordem
void print_tree_pos(TREE* a);
#endif