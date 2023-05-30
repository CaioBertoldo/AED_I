#ifndef LISTA_H_INCLUDE
#define LISTA_H_INCLUDE

typedef struct lista{ 
    int *vector;
    int size;
}Lista;

Lista *create(int num);

void release(Lista *out);

void insert_list(Lista *list);

void insert_list_ord(Lista *list_ord);

void print_list(Lista list);

void sequential_search(Lista *list, int value);

void sequential_search_ord(Lista *list_ord, int value);

int binary_search(Lista *list_ord, int value);

int binary_search_recursive(Lista *list_ord, int value, int start, int end, int comp);

void print_list_recursive(Lista *list, int index);

void bigger(Lista *list);

int bigger_recursive(Lista *list, int size, int index);

void smaller(Lista *list);

int smaller_recursive(Lista *list, int size, int index);

void sum_list(Lista *list);

int sum_list_recursive(Lista *list, int size);

void product_list(Lista *list);

int product_list_recursive(Lista *list,int size);
#endif
