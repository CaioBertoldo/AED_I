#ifndef TURMA2_H_INCLUDE
#define TURMA2_H_INCLUDE

#define max 100
typedef struct aluno{
    char *nome;
    int idade;
    int code;
}Aluno;

typedef struct elemento{
    Aluno student;
    int prox;
}Elemento;

typedef struct lista{
    Elemento turma[max];
    int inicio;
    int disponivel;
}Lista;

#endif