#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE
#define max 20

typedef struct{
    int code;
    char *nome;
    int idade;
    int num_filhos;
}Aluno;

typedef struct{
    Aluno al;
    int next;
}Elemento;

typedef struct{
    Elemento turma[max];
    int inicio;
    int disponivel;
}Lista;

// função para criar a lista de alunos
void criar(Lista *list);

// verificar o tamanho da lista
int tamanho_lista(Lista *list);

// Função para verificar espaço disponível
int obterNo(Lista *list);

// Inserir alunos sem importar a ordem
int inserir_aluno(Lista *list, Aluno new);

//Inserir alunos de forma ordenada
int inserir_aluno_ord(Lista *list, Aluno new);

// Função para buscar aluno
int busca(Lista *list, int num);

// Função para definir que o espaço do elemento que será excluido vai ficar disponível
void alocarNo(Lista *list, int i);

// Função para excluir aluno pelo valor
int excluir_aluno(Lista *list, int num);

// Função para imprimir a lista
void imprimir_lista(Lista *list);
#endif