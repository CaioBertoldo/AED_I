#ifndef PROVA_H_INCLUDE
#define PROVA_H_INCLUDE
#define max 20

typedef struct{
    int codigo;
    char *nome;
    int idade;
    int num_filhos;
}Aluno;

typedef struct{
    Aluno al;
    int prox;
}Elemento;

typedef struct{
    Elemento turma[max];
    int inicio;
    int disponivel;
}Lista;

// função para criar a lista de alunos
void criar(Lista *list);

int obterNo(Lista *list);

int inserir_aluno_ord(Lista *list, Aluno new_aluno);

void imprimir(Lista *list);

int menor(Lista *l);

void imprimir_menor(Lista *l);
#endif