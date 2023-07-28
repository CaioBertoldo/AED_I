#ifndef PROVA2_H_INCLUDE
#define PROVA2_H_INCLUDE
#define max 20

typedef struct{
    int code;
    char *nome;
    int idade;
    int num_filhos;
}Aluno;

typedef struct{
    Aluno *al;
    int qtd;
}Lista;

Lista *criar(int tam);

int inserir_elementos(Lista *list, Aluno al1);

void imprimir(Lista *l);

int maior_igual_idade(Lista *l, int idade);
#endif