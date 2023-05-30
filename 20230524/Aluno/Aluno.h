#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE

typedef struct aluno{
    int code;
    char name[30];
    int age;
    float coefficient;
}Aluno;


typedef struct turma{
    Aluno *list;
    int quantity;
}Turma;

Turma *create(int num);

void  insert_students(Turma *a1);

void release(Turma *class);

void sequential_search(Turma *a1, int cod);

void print_class(Turma *a1);

int binary_search_recursive(Turma *a1, int cod, int start, int end);
#endif
