#ifndef TURMA_H_INCLUDE
#define TURMA_H_INCLUDE

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

void start_list(Lista *class);

void release(Lista *class);

int valid_elements(Lista *class);

int list_full(Lista *class);

int list_empyt(Lista *class);

void print_elements(Lista *class);

int obterNo(Lista *class);

int insert_student(Lista *class, Aluno new_aluno);

void alocaNo(Lista *class, int i);

int delete_student(Lista *class, int code);

int search_lista(Lista *class, int code);

int altera_cod(Lista *class, int code, int new_code);
#endif