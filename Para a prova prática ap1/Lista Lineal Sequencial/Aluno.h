#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE
#define max 20

typedef struct{
    int code;
    int qtd;
    char nome[max];
    int idade;
    int num_filhos;
}Lista;

// Inicializar a lista
Lista *criar(int size);

//Inserir aluno na lista na lista sem importar a ordem, no inicio
int inserir_elementos(Lista *list, int code);

// Busca sequencial
int busca_sequencial(Lista *list, int valor);

// Busca sequencial ordenada
int busca_sequencial_ordenada(Lista *list, int valor);

// Inserir aluno pela posição indicada pelo usuário
int inserir_elemento_pos(Lista *list, int pos, int num);

//Inserir aluno de forma ordenada
int inserir_aluno_ordenado(Lista *list, int code);

// Quantidade de elementos da lista
int tamanho_lista(Lista *list);

// Busca binária de elementos da lista
int busca_binaria(Lista *list, int valor);

// Excluir aluno pela posição
int excluir_aluno_pos(Lista *list, int pos);

//Imprimir elementos da lista
void imprimir_elementos(Lista *list);
#endif