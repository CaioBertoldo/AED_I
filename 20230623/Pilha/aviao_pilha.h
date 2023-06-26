#ifndef AVIAO_PILHA_H_INCLUDE
#define AVIAO_PILHA_H_INCLUDE

typedef struct{
    int identificador;
    char *nome;
}Aviao;

typedef struct aux{
    Aviao avi;
    struct aux* prox;
}Elemento;

typedef struct{
    Elemento* topo;
}Pilha;

void incicializa(Pilha* p);

void reinicializar(Pilha* p);

int numero_avioes(Pilha* p);

int decolar(Pilha *p);

int inserir_aviao(Pilha* p, Aviao novo);

void Listar_avioes(Pilha* p);

Elemento* primeiro_elemento(Pilha* p);

void primeiro_aviao(Pilha *p);

int excluir_pos(Pilha* p, int pos);
#endif