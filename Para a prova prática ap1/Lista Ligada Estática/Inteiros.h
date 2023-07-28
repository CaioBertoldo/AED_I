#ifndef INTEIROS_H
#define INTEIROS_H
#define MAX 20

typedef struct{
    int num;
    int next;
}Elemento;

typedef struct{
    Elemento enumerar[MAX];
    int inicio;
    int disp;
}Lista;

// Incicializar a lista
void criar(Lista *list);

// Retornar o tamanho da lista
int tamanho_lista(Lista *list);

// Função para verificar espaço disponível
int obterNo(Lista *list);

// Inserir elemento sem importar a ordem
int inserir_elemento(Lista *list, int nun);

// Inserir elemento de forma ordenada
int inserir_elemento_ord(Lista *list, int num);

// Busca sequencial
int busca_sequencial(Lista *list, int num);

//Excluir elemento pelo valor
int excluir_elemento(Lista *list, int valor);

// Função para dizer que a posição que está excluindo agora está disponível
void alocarNo(Lista *list, int i);

//Imprimir os elementos da lista
void imprimir_lista(Lista *list);

#endif

