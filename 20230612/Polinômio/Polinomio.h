#ifndef POLINOMIO_H_INCLUDE
#define POLINOMIO_H_INCLUDE

typedef struct aux{
    int exp;
    int coef;
    struct aux* next;
}EXPOENTE;

typedef struct {
    EXPOENTE* start;
}Polinomio;

void start_polinomio(Polinomio *p);

EXPOENTE *search_exp_pred(Polinomio *p, int exponet,int coefficient, EXPOENTE **pred);

int insert_polinomio(Polinomio *p, int exponet, int coefficient);

void restart(Polinomio *p);

void print_polinomio(Polinomio *p);

int sum_polinomio(Polinomio *p1, Polinomio *p2, Polinomio *p3);
#endif
