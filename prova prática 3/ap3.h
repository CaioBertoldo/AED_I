#ifndef AP3_H_INCLUDE
#define AP3_H_INCLUDE

typedef struct{
    int num;
}NUMERO;

typedef struct aux{
    NUMERO num;
    struct aux* esquerda;
    struct aux* direita;
}NO;

typedef struct{
    NO* raiz;
}ARVORE;

// Inicializar a árvore
void inicializa_arvore(ARVORE* a);

// Criar um nó 
NO* criar_no(NUMERO n);

// Inserir o nó na árvore
NO* inserir(NO* raiz, NO* no);

// Adicioonar na árvore
int adiciona(ARVORE* a, NO* novo);

// Imprimir os nós da árvore
void imprimir_nos(NO* raiz);

// Imprimir os elementos da árvore
void imprimir_arvore(ARVORE* a);

// Contar quantos elementos tem na árvore
int numero_nos(NO* raiz);

// Função de buscar nós
NO* busca(NO* raiz, int n);

// Função de buscar na árvore
NO* buscar_arvore(ARVORE* a, int n);

// linha
void linha();

// Percorrer a árvore em pré ordem
void pre_ordem(NO* raiz);

// Mostrar na árvore pre ordem
void mostrar_pre_ordem(ARVORE* a);

// Percorre in ordem
void in_ordem(NO* raiz);

// Mostrar na árvore em in ordem
void mostrar_in_ordem(ARVORE* a);

// Percorrer arvore pos ordem
void pos_ordem(NO* raiz);

// Mostrar na árvore em pos ordem
void mostrar_pos_ordem(ARVORE* a);

void maiores(NO* raiz, int value);

void maioresa(ARVORE* a, int value);
#endif