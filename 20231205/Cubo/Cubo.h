#ifndef CUBO_H_INCLUDE
#define CUBO_H_INCLUDE

typedef struct cubo{
    float medida;
}Cubo;

Cubo *preencher_cubo(float x);
void retorna_dados(Cubo *ptr);
void libera(Cubo *cub);

#endif