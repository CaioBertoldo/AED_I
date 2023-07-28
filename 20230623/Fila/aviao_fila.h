#ifndef AVIAO_FILA_H_INCLUDE
#define AVIAO_FILA_H_INCLUDE

typedef struct{
    int identificador;
    char *nome;
}Aviao;

typedef struct aux{
    Aviao avi;
    struct aux* prox;
}Elemento;

typedef struct{
    Elemento* inicio;
    Elemento* fim;
}Fila;


void inicializa(Fila* f);

void reinicializar(Fila* f);

int qtd_avioes(Fila *f);

int liberar_aviao(Fila *f);

int inserir_aviao(Fila *fila, Aviao novo);

void listar_avioes(Fila *f);

Elemento *primeiro_elemento(Fila* f);

void primeiro_aviao(Fila* f);
#endif