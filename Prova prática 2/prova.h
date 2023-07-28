#ifndef PROVA_H_INCLUDE
#define PROVA_H_INCLUDE

typedef struct aux{
    int num;
    struct aux* anterior;
    struct aux* proximo;
}Elemento;

typedef struct{
    Elemento* cabeca;
}Deque;

void inicializa(Deque* d);

void reinicializa(Deque* d);

int inserir(Deque* d, int n);

void mostrar_deque(Deque* d);

int intercalar(Deque* d1, Deque* d2, Deque* d3);
#endif