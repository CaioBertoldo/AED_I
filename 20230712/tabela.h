#ifndef EX2_H_INCLUDE
#define EX2_H_INCLUDE
#define MAX 9

typedef struct aux{
    int num;
    struct aux* proximo;
}ELEMENTO;

typedef ELEMENTO* TB_HASH[MAX];

// Incicializar a tabela hash
void incicializa_hash(TB_HASH tabela);

// Função de dispersão (onde vai inserir o paciente na tabela)
int dispersao(int k);

// Inserir elementos na lista
int inserir(TB_HASH tabela, int num);

// Imprimir a tabela hash
void imprimir_hash(TB_HASH tabela);

#endif
