#ifndef HASH2_H_INCLUDE
#define HASH2_H_INCLUDE
#define MAX 11

typedef struct {
    int num;
}NUMERO;

typedef NUMERO* TB_HASH[MAX];

// Função para inicializar a tabela hash
void inicializa_hash(TB_HASH tabela);

// Função de dispersão (sondagem linear)
int dispersao_a(int k, int i);

// Funçao de dispersão (sondagem quadrática)
int dispersao_b(int k, int i);

// Funçao de dispersão (sondagem quadrática 2)
int dispersao_c(int k, int i);

// Função de dispersão (normal, para usar com hash duplo)
int dispersao(int k);

// Função de dispersão (hash duplo)
int dispersao_d(int k);

// Inserir elemento com posição consecutiva livre
int inserir(TB_HASH tabela, int n);

// Imprimir a tabela hash
void imprimmir(TB_HASH tabela);

#endif