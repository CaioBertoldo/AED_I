#ifndef COMPLEXO_H_INCLUDE
#define COMPLEXO_H_INCLUDE

typedef struct complexo{
    float real, imag;
}Complexo;

Complexo *criar(float x, float y);
void destruir(Complexo *n1, Complexo *n2);
void somar(Complexo *n1, Complexo *n2);
void subtrair(Complexo *n1, Complexo *n2);
void multiplicar(Complexo *n1, Complexo *n2);
void dividir(Complexo *n1, Complexo *n2);
void linha();

#endif
