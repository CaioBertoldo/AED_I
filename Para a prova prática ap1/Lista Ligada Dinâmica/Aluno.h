#ifndef ALUNO_H_INCLUDE
#define ALUNO_H_INCLUDE

typedef struct{
    int code;
    char *nome;
    int idade;
    int num_filhos;
}Aluno;

typedef struct aux{
    Aluno al;
    struct aux* next;
}Elemento;

typedef struct{
    Elemento *inicio;
}Lista;

//Função para inicializar a lista
void criar(Lista *list);

// Retornar o tamanho da lista
int tamanho(Lista *list);

// Busca sequencial 
Elemento* busca_sequencial(Lista *list, int num);

// Busca sequencial ordenada
Elemento* busca_sequencial_ord(Lista *list, int num);

//Função auxiliar para inserir valores de forma não ordenada
Elemento* busca_elem_pred(Lista *list, int cod_al, Elemento **pred);

//Inserir alunos de forma não ordenada
int inserir_aluno(Lista* list, Aluno new_al);

// Função auxiliar para inserir alunos de forma ordenada
Elemento* busca_elem_pred_ord(Lista *list, int cod_al, Elemento **pred);

//Inserir elementos de forma ordenada na lista
int inserir_aluno_ord(Lista* list, Aluno new_al);

//Excluir aluno
int excluir_aluno(Lista* list, int cod_al);

// Reinicializar a lista
void restart(Lista *list);

//imprimir a lista
void imprimir_lista(Lista *list);
#endif