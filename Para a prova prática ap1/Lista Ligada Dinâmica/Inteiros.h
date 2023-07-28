#ifndef INTEIROS_H_INCLUDE
#define INTEIROS_H_INCLUDE


typedef struct aux{
    int num;
    struct aux* next;
}Elemento;

typedef struct{
    Elemento* inicio;
}Lista;

// Função para inicializar a lista
void criar(Lista *list);

// Função para retornar o tamanho da lista
int tamanho(Lista *list);

//Busca sequencial
Elemento* busca_sequencial(Lista *list, int num);

//Busca sequencial ordenada
Elemento* busca_sequencial_ord(Lista *list, int num);

//Função auxiliar para inserir elementos na lista, sem ordenar
Elemento* busca_elemento_pred(Lista *list, int num, Elemento **pred);

//Função para inserir elementos na lista, sem ordenar
int inserir_elemento(Lista *list, int num);

//Função auxiliar para inserir elementos na lista de forma ordenada
Elemento* busca_elemento_pred_ord(Lista *list, int num, Elemento **pred);

// Função de inserir ordenado
int inserir_elemento_ord(Lista *list, int num);

//Exluir um elemento da lista
int excluir_elemento(Lista *list, int num);

//Função de reinicializar a lista
void reinicializar(Lista *list);

//Imprimir os elementos da lista
void imprimir_lista(Lista *list);
#endif