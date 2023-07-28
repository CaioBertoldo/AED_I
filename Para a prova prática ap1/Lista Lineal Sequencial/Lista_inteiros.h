#ifndef LISTA_INTEIROS_H_INCLUDE
#define LISTA_INTEIROS_H_INCLUDE
#define max 20

typedef struct{
    int *vector;
    int qtd;
}LISTA;

// Função para criar a lista
LISTA *criar(int size);

// Função para verificar se a lista está cheia
int lista_cheia(LISTA *list);

// Função para verficar se a lista está vazia
int lista_vazia(LISTA *list);

// Função para inserir elemento no início da lista, sem importar a ordem
int inserir_elementos(LISTA *list, int num);

// FunÇÃO de busca sequencial
int busca_sequencial(LISTA *list, int valor);

// Função de busca sequencial ordenada
int busca_sequencial_ordenada(LISTA *list, int valor);

// Função de busca binária
int busca_binaria(LISTA *list, int valor);

// Função para inserir elemento na posição indicada pelo usuário
int inserir_elemento_pos(LISTA *list, int pos, int num);

// Função para inserir elemento de forme ordenada
int inserir_elemento_ordenado(LISTA *list, int valor);

// Função que retorna o tamanho da lista
int tamanho_lista(LISTA *list);

//Função de excluir um elemento pela posição
int excluir_elemento_pos(LISTA *list, int pos);

//Função para imprimir os elementos da lista
void imprimir_lista(LISTA *list);

// Liberar a lista
void liberar(LISTA *list);
#endif