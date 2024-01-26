#ifndef AB_H_INCLUDE
#define AB_H_INCLUDE

typedef struct aux{
    char exp;
    struct aux* left;
    struct aux* right;
}Node;

typedef struct{
    Node* root;
}Tree;

typedef struct aux2{
    char exp;
    struct aux2* next;
}Element;

typedef struct{
    Element* start;
    Element* end;
}Queue;

// Função para inicializar a árvore
void create_tree(Tree* a);

// Função para criar um nó
Node* crate_node(char exp);

// Função para inserir um elemento na árvore binária
Node* insert_node(Node* root, char exp);

// Função para inserir na árvore
int insert_tree(Tree* a, char new);

// Função para percorrer a árvore em ordem (infixa)
void in_ord(Node* root);

// Função para imprimir a árvore na ordem infixa
void print_tree_infx(Tree* a);

// Função para percorrer em pré ordem (prefixa)
void pre_ord(Node* root);

// Função para imporimir a árvore em ordem prefixa
void print_tree_prfx(Tree* a);

// Função para percorrer em pós ordem (posfixa)
void pos_ord(Node* root);

// Função para imprimir a árvore em odem posfixa
void print_tree_psfx(Tree* a);

// Iniciializar a fila
void create_queue(Queue* f);

// Reinicializar a fila
void restart_queue(Queue* f);

// Inserir na fila
int insert_queue(Queue* f, char exp);

// Excluir da fila
int clear_queue(Queue* f);
#endif
