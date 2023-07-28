#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "esp1.h"

void criarExpressao(ExpressaoAritmetica *expressao, char *string) {
    expressao->expressao = strdup(string); // Alocar memória para a expressÃ£o e copiar a string fornecida
}

void apagarExpressao(ExpressaoAritmetica *expressao) {
    free(expressao->expressao); // Liberar a memória alocada para a expressÃ£o
}

void imprimirExpressao(ExpressaoAritmetica *expressao) {
    printf("Expressao infixa: %s\n", expressao->expressao); // Imprimir a expressão aritmética no console
}
 
int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Verificar se o caractere é um operador (+, -, *, /)
}

void converterParaPrefixa(ExpressaoAritmetica *expressao, char *prefixa) {
    int i, j = 0;
    int tamanho = strlen(expressao->expressao);

    char pilha[tamanho];
    int topo = -1;

    for (i = tamanho - 1; i >= 0; i--) {
        char c = expressao->expressao[i];

        if (c == ' ') {
            continue; // Ignorar espaÃ§os em branco na expressão
        } else if (c == ')') {
            topo++;
            pilha[topo] = c; // Empilhar o caractere ')' na pilha
        } else if (c == '(') {
            while (topo >= 0 && pilha[topo] != ')') {
                prefixa[j++] = pilha[topo]; // Desempilhar operadores até encontrar o caractere ')'
                topo--;
            }
            topo--;  // Desconsiderar o ")"
        } else if (ehOperador(c)) {
            while (topo >= 0 && prioridade(pilha[topo]) > prioridade(c)) {
                prefixa[j++] = pilha[topo]; // Desempilhar operadores com prioridade maior
                topo--;
            }
            topo++;
            pilha[topo] = c; // Empilhar o operador atual
        } else {
            prefixa[j++] = c; // Copiar operandos para a expressão prefixa
        }
    }

    while (topo >= 0) {
        prefixa[j++] = pilha[topo]; // Desempilhar os operadores restantes
        topo--;
    }

    // Inverter a string prefixa
    int left = 0, right = j - 1;
    while (left < right) {
        char temp = prefixa[left];
        prefixa[left] = prefixa[right];
        prefixa[right] = temp;
        left++;
        right--;
    }

    prefixa[j] = '\0'; // Adicionar o caractere nulo de terminação da string
}

int prioridade(char c) {
    if (c == '+' || c == '-')
        return 1; // Operadores de prioridade mais baixa
    else if (c == '*' || c == '/')
        return 2; // Operadores de prioridade mais alta
    return 0; // Caracteres que não são operadores
}

int avaliarPrefixa(char *prefixa) {
    int i, topo = -1;
    int tamanho = strlen(prefixa);

    int pilha[tamanho];

    for (i = tamanho - 1; i >= 0; i--) {
        char c = prefixa[i];

        if (ehOperador(c)) {
            int operando1 = pilha[topo];
            topo--;
            int operando2 = pilha[topo];
            topo--;

            int resultado;
            if (c == '+') {
                resultado = operando1 + operando2;
            } else if (c == '-') {
                resultado = operando1 - operando2;
            } else if (c == '*') {
                resultado = operando1 * operando2;
            } else if (c == '/') {
                resultado = operando1 / operando2;
            }

            topo++;
            pilha[topo] = resultado; // Empilhar o resultado da operação
        } else {
            topo++;
            pilha[topo] = c - '0';  // Converter caractere numérico para inteiro e empilhar
        }
    }

    return pilha[topo]; // Retornar o resultado final da expressão aritmética
}