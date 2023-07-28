#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "esp1.h"

int main() {
    ExpressaoAritmetica expressao;
    criarExpressao(&expressao, "(5+3)*4");

    imprimirExpressao(&expressao); // Imprime a expressão aritmética original no console

    char prefixa[50];
    converterParaPrefixa(&expressao, prefixa); // Converte a expressÃ£o para notação prefixa e a armazena em prefixa[]
    printf("Expressao prefixa: %s\n", prefixa); // Imprime a expressão aritmética na notação prefixa no console

    int resultado = avaliarPrefixa(prefixa); // Avalia a expressão prefixa e armazena o resultado em resultado
    printf("Resultado da expressao: %d\n", resultado); // Imprime o resultado da expressão aritmética no console

    apagarExpressao(&expressao); // Libera a memória alocada pela expressão

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
