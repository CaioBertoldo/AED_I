#ifndef LISTA_H
#define LISTA_H
#define MAX 10

typedef struct
{
    int element;
    int next;
}Elemento;

typedef struct 
{
    Elemento list_elem[MAX];
    int start;
    int available;
}Lista;

void start_list(Lista *list);

int obetrNo(Lista *list);

int insert_elements(Lista *list, int new_element);

int size_list(Lista *list);

void print_list(Lista *list);

int letra_a(Lista *list);
#endif
