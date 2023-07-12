#ifndef ENCADEADA_H_INCLUDE
#define ENCADEADA_H_INCLUDE
#define MAX 100

typedef struct{
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
}PACIENTE;

typedef struct aux{
    PACIENTE pac;
    struct aux* proximo;

}ELEMENTO;

typedef ELEMENTO* TB_HASH[MAX];

// Incicializar a tabela hash
void incicializa_hash(TB_HASH tabela);

// Função de dispersão (onde vai inserir o paciente na tabela)
int dispersao(int codigo_paciente);

// Inserir elementos na lista
int inserir(TB_HASH tabela, PACIENTE paciente);

// Imprimir a tabela hash
void imprimir_hash(TB_HASH tabela);

// Função para excluir pacientes da tabela hash
int excluir(TB_HASH tabela, int cod_pac);

#endif