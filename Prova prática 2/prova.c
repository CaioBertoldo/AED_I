#include <stdio.h>
#include <stdlib.h>
#include "prova.h"


void inicializa(Deque* d){
    d->cabeca = malloc(sizeof(Elemento));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void reinicializa(Deque* d){
    Elemento* apagar;
    Elemento* i = d->cabeca->proximo;
    while(i != d->cabeca){
        apagar = i;
        i = i->proximo;
        free(apagar);
    }
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

int inserir(Deque* d, int n){
    Elemento* i;
    i = malloc(sizeof(Elemento));
    i->num = n;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior = i;
    i->anterior->proximo = i;
    return 1;
}

void mostrar_deque(Deque* d){
    Elemento* i = d->cabeca->proximo;
    while(i != d->cabeca){
        printf(" %d, ", i->num);
        i = i->proximo;
    }
}

int intercalar(Deque* d1, Deque* d2, Deque* d3){
    Elemento* i = d1->cabeca->proximo;
    Elemento* j = d2->cabeca->proximo;
    Elemento* k = d3->cabeca->proximo;
    while(i != d1->cabeca && j != d2->cabeca){
        inserir(d3, i->num);
        inserir(d3, j->num);
        i = i->proximo;
        j = j->proximo;
    }
}
