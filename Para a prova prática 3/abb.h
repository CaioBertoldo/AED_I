#ifndef ABB_H_INCLUDE
#define ABB_H_INCLUDE

typedef struct aux{
    int num;
    struct aux* esquerda;
    struct aux* direita;
}NO;

typedef struct {
    NO* raiz;
}ARVORE;


#ifndef