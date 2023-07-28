#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

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

int inserir_aluno(Deque* d, Aluno novo){
    Elemento* i;
    i = malloc(sizeof(Elemento));
    i->al = novo;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo = i;
    i->anterior->proximo = i;
    return 1;
}

void linha(){
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void mostrar_deque(Deque* d){
    Elemento* i = d->cabeca->proximo;
    while(i != d->cabeca){
        printf("\nNome do aluno: %s", i->al.nome);
        printf("\nMatrucula do aluno: %d", i->al.matricula);
        linha();
        i = i->proximo;
    }
}

Elemento* acessar_fim(Deque* d){
    return d->cabeca->anterior;
}

Elemento* acessar_inicio(Deque* d){
    return d->cabeca->proximo;
}

int tamanho(Deque* d){
    int tam = 0;
    Elemento*i = d->cabeca;
    while(i != d->cabeca){
        tam++;
        i = i->proximo;
    }
    return tam;
}

void exibir(Deque* d, int pos, char ordem){
    Elemento* i = d->cabeca->proximo;
    int j;
    if(ordem == 'd'){
        for(j = pos; j < tamanho(d); j++){
            printf("\nNome do aluno: %s", i->al.nome);
            printf("\nMatricula do aluno: %d", i->al.matricula);
            linha();
            i = i->proximo;
        }
    }else if(ordem == 'i'){
        for(j = pos; j < tamanho(d); j--){
            printf("\nNome do aluno: %s", i->al.nome);
            printf("\nMatricula do aluno: %d", i->al.matricula);
            linha();
            i = i->anterior;
        }
    }
}
