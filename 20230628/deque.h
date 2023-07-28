#ifndef DEQUE_H_INCLUDE
#define DEQUE_H_INCLUDE
#define max 40

typedef struct{
    char *nome;
    int matricula;
}Aluno;

typedef struct aux{
    Aluno al;
    struct aux* anterior;
    struct aux* proximo;
}Elemento;

typedef struct{
    Elemento* cabeca;
}Deque;

void inicializa(Deque* d);

void reinicializa(Deque* d);

int inserir_aluno(Deque* d, Aluno novo);

void linha();

void mostrar_deque(Deque* d);

Elemento* acessar_fim(Deque* d);

Elemento* acessar_inicio(Deque* d);

void exibir(Deque* d, int pos, char ordem);

int tamanho(Deque* d);
#endif