#ifndef ESP1_H_INCLUDE
#define ESP1_H_INCLUDE

typedef struct {
    char *expressao;  // Estrutura que armazena uma expressão aritmética como uma string
} ExpressaoAritmetica;

void criarExpressao(ExpressaoAritmetica *expressao, char *string);
// Função para criar uma expressão aritmética. Recebe a estrutura ExpressaoAritmetica e uma string como parâmetro.

void apagarExpressao(ExpressaoAritmetica *expressao);
// Função para liberar a memória alocada para a expressão aritmética.

void imprimirExpressao(ExpressaoAritmetica *expressao);
// Função para imprimir a expressão aritmética no console.

int ehOperador(char c);
// Função para verificar se um caractere é um operador aritmético (+, -, *, /).

void converterParaPrefixa(ExpressaoAritmetica *expressao, char *prefixa);
// Função para converter uma expressão aritmética para notação prefixa.

int prioridade(char c);
// Função para retornar a prioridade de um operador aritmético.

int avaliarPrefixa(char *prefixa);
// Função para avaliar uma expressão aritmética na notação prefixa e retornar o resultado.

#endif