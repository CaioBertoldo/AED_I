#ifndef EX01_H_INCLUDE
#define EX01_H_INCLUDE
#define max 20
typedef struct{
    int code;
    char *name;
    int idade;
    int num_filhos;
}Aluno;


typedef struct{
    Aluno *al;
    int prox;
}Elemento;

typedef struct{
    Elemento turma[max];
    int inicio;
    int disponivel;
}Lista;

void inicializar(Lista *l);

int busca_matricula(Lista *l, int cod_al);

int obterNo(Lista *l);

int inserir_aluno(Lista *list, Aluno new);

void imprimir_lista(Lista *list);
#endif