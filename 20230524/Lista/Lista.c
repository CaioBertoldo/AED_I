#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *create(int num){
    Lista *out = malloc(sizeof(Lista));
    out->size = num;
    out->vector = malloc(num*sizeof(int));

    return out;
}

void release(Lista *out){
    free(out->vector);
    free(out);
}

void insert_list(Lista *list){
    printf("\n----  FUNCAO DE INSERIR VALORES NA LISTA ----");
    int i;
    for(i=0; i < list->size; i++){
        printf("\nDigite um numero: ");
        scanf("%d", &list->vector[i]);
    }
}

void insert_list_ord(Lista *list_ord){
    printf("\n----  FUNCAO DE INSERIR VALORES ORDENADOS NA LISTA ----");
    int i;
    for(i = 0; i < list_ord->size; i++){
        printf("\nValor na posicao %d: ", i);
        scanf("%d", &list_ord->vector[i]);
        if(i > 0){
            while(list_ord->vector[i] < list_ord->vector[i - 1]){
                printf("\nInsira um valor maior que %d: ", list_ord->vector[i - 1]);
                scanf("%d", &list_ord->vector[i]);
            }
        }
    }
    for(i = 0; i < list_ord->size; i++){
        printf("\n Valor %d na posicao %d", list_ord->vector[i], i+1);
    }
}

void print_list(Lista list){
    printf("\n---- FUNCAO PARA PRINTAR A LISTA 1 ----");
    int i;
    for(i = 0; i < list.size; i++){
        printf("\nValor %d na posicao %d", list.vector[i], i+1);
    }
}

void sequential_search(Lista *list, int value){
    int i;
    int comp;
    for(i = 0; i < list->size; i++){
        comp += 1;
        if(list->vector[i] != value){
            printf("\nBusando o valor... ");
        }
        if(list->vector[i] == value){
            printf("\n Valor encontrado na posiao %d, %d comparacoes", i+1, comp);
            break;
        }
    }
}

void sequential_search_ord(Lista *list_ord, int value){
    int i;
    int comp;
    for(i = 0; i < list_ord->size; i++){
        comp ++;
        if(list_ord->vector[i] != value){
            printf("\nBuscando o valor... ");
        }
        if(list_ord->vector[i] == value){
            printf("\nValor encontrado na posicao %d, %d comparacoes", i+1, comp);
            break;
        }
    }
}

int binary_search(Lista *list_ord, int value){
    int first = 0;
    int last = list_ord->size - 1;
    int middle = -1;
    int comp;

    while(first <= last){
        comp ++;
        middle = first + (last - first) / 2;
        if(value == list_ord->vector[middle]){
            return middle + 1;
        } else if(value > list_ord->vector[middle]){
            first = middle + 1;
        } else{
            last = middle - 1;
        }
    }
    printf("\nForam feitas %d comparacoes", comp);
    return -1;
}

int binary_search_recursive(Lista *list_ord, int value, int start, int end, int comp){
    if(start > end){
        return -1;
    }
    int middle = (start + end) / 2;
    if(value == list_ord->vector[middle]){
        return middle;
    }
    if(value < list_ord->vector[middle]){
        binary_search_recursive(list_ord, value, start, middle-1, comp+1);
    }
    else{
        binary_search_recursive(list_ord, value, middle+1, end, comp+1);
    }
}

void print_list_recursive(Lista *list, int index){
    if(index == list->size){
        return;
    }
    else{
        printf("%d ", list->vector[index]);
        print_list_recursive(list, index + 1);
    }
}

void bigger(Lista *list){
    int big=0;
    int i;
    for(i = 0; i < list->size; i++){
        if(i == 0){
            big = list->vector[i];
        }else if(list->vector[i] > big){
            big = list->vector[i];
        }
    }
    printf("\nO maior elemento eh o %d", big);
}

int bigger_recursive(Lista *list, int size, int index){
    if(size == 0){
        return list->vector[index];
    }else if(list->vector[size - 1]> list->vector[index]){
        return bigger_recursive(list, size - 1, size - 1);
    }else{
        return bigger_recursive(list, size - 1, index);
    }
}

void smaller(Lista *list){
    int small=0;
    int i;
    for(i = 0; i < list->size; i++){
        if(i == 0){
            small = list->vector[i];
        }else if(list->vector[i] < small){
            small = list->vector[i];
        }
    }
    printf("\nO menor elemento eh o %d", small);
}

int smaller_recursive(Lista *list, int size, int index){
    if(size == 0){
        return list->vector[index];
    }else if(list->vector[size - 1] < list->vector[index]){
        return smaller_recursive(list, size - 1, size - 1);
    }else{
        return smaller_recursive(list, size - 1, index);
    }
}

void sum_list(Lista *list){
    int sum = 0;
    int i;
    for(i = 0; i < list->size; i++){
        sum += list->vector[i];
    }
    printf("\nA soma dos elementos do vetor eh %d", sum);
}

int sum_list_recursive(Lista *list, int size){
    if(size == 0){
        return 0;
    }
    else{
        return list->vector[size - 1] + sum_list_recursive(list, size - 1);
    }
}

void product_list(Lista *list){
    int prod=1;
    int i;
    for(i = 0; i < list->size; i++){
        prod *= list->vector[i];
    }
    printf("\nO produto dos elementos do vetor eh %d", prod);
}

int product_list_recursive(Lista *list,int size){
    if(size == 0){
        return 1;
    }
    else{
        return list->vector[size - 1] * product_list_recursive(list, size - 1);
    }
}
