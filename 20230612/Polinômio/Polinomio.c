#include <stdio.h>
#include <stdlib.h>

#include "Polinomio.h"

void start_polinomio(Polinomio *p){
    p->start = NULL;
}

EXPOENTE *search_exp_pred(Polinomio *p, int exponet,int coefficient, EXPOENTE **pred){
    *pred = NULL;
    EXPOENTE *current = p->start;
    while((current != NULL) && (current->exp > exponet)){
        *pred = current;
        current = current->next;
    }
    if((current != NULL) && (current->exp == exponet)){
        current->coef += coefficient;
        return current;
    }
    return NULL;
}

int insert_polinomio(Polinomio *p, int exponet, int coefficient){
    int new_exp = exponet;
    EXPOENTE *i;
    EXPOENTE *pred;
    int new_coef = coefficient;

    i = search_exp_pred(p, new_exp, new_coef, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(EXPOENTE));
    i->exp = exponet;
    i->coef = coefficient;
    if(pred == NULL){
        i->next = p->start;
        p->start = i;
    }else{
        i->next = pred->next;
        pred->next = i;
    }
    return 1;
}

void restart(Polinomio *p){
    EXPOENTE *clear;
    EXPOENTE *i = p->start;
    while(i !=  NULL){
        EXPOENTE* clear = i;
        i = i->next;
        free(clear);
    }
    p->start = NULL;
}

void print_polinomio(Polinomio *p){
    EXPOENTE *i = p->start;
    while(i != NULL){
        if(i->exp == 0){
            printf("%d", i->coef);
        }else if(i->exp == 1){
            printf("%dx", i->coef);
        }else{
            printf("%dx^%d",i->coef, i->exp);
        }    
        if(i->next != NULL){
            printf(" + ");
        }
        i = i->next;
    }
}

int sum_polinomio(Polinomio *p1, Polinomio *p2, Polinomio *p3){
    if(p3->start != NULL){
        return 0;
    }
    EXPOENTE *i = p1->start;
    EXPOENTE *j = p2->start;
    
    while(i != NULL){
        insert_polinomio(p3, i->exp, i->coef);
        i = i->next;
    }

    while(j != NULL){
        insert_polinomio(p3, j->exp, j->coef);
        j = j->next;

    }
    return 1;
}
