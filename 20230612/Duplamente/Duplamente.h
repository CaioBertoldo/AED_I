#ifndef DUPLAMENTE_H_INCLUDE
#define DUPLAMENTE_H_INCLUDE


typedef struct aux{
    int element;
    struct aux* next;
    struct aux* ant;
}Node;


typedef struct Lista{
    Node *start;
}Lista;

void start_list(Lista *list);

Node* search_element_pred(Lista *list, int num, Node **pred);

int insert_element(Lista *list, int num);

void print_list(Lista *list);

void restart(Lista *list);

int size_list(Lista *list);

Node* maior(Lista *list);

int kill(Lista *list, Node *element);

int insert_value_start(Lista *list);
#endif
