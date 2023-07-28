#include <stdio.h>
#include <stdlib.h>

#include "Turma2.h"

void start_list(Lista *class){
    class->inicio = NULL;
}

void release(Lista *class){
    Elemento *apagar;
    Elemento *elem = class->inicio;

    while(elem != NULL){
        Elemento *apagar = elem;
        elem = elem->prox;
        free(apagar);
    }
    class->inicio = NULL;
}

int valid_elements(Lista *class){
    int size=0;
    Elemento *i = class->inicio;

    while(i != NULL){
        size++;
        i = i->prox;
    }
    return size;
}

int list_full(Lista *class){
    if(valid_elements(class) == 0){
        return 0;
    } else if(valid_elements(class) == max){
        return 1;
    }
}

int list_empty(Lista *class){
    if(valid_elements(class) == 0){
        return 1;
    }else if(valid_elements(class) != 0){
        return 0;
    }
}

