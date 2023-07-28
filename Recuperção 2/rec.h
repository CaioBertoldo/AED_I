#ifndef REC_H_INCLUDE
#define REC_H_INCLUDE

typedef struct aux{
    char letra;
    struct aux* prox;
}Elemento;

typedef struct{
    Elemento* inicio;
    Elemento* fim;
}Fila;

typedef struct aux2{
    char letra_pilha;
    struct aux2* prox;
}Elemento_pilha;

typedef struct{
    Elemento_pilha* topo;
}Pilha;

void inicializa_fila(Fila* f);

void reinicializar_fila(Fila* f);

int inserir_fila(Fila *fila, char letra);

char liberar_fila(Fila *f);

void imrpimir_frase(Fila *f);

void incicializa_pilha(Pilha* p);

void reinicializar_pilha(Pilha* p);

int inserir_pilha(Pilha* p, char letra);

int transferir(Fila* f, Pilha* p);

void imprimir_pilha(Pilha* p);
#endif