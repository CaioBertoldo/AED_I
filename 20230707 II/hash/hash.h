#ifndef HASH_H_INCLUDE
#define HASH_H_INCLUDE
#define MAX 100

typedef struct{
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
}Paciente;

typedef Paciente* TB_HASH[MAX];

// Função para inicializar a tabela hash
void inicializa_hash(TB_HASH tabela);

// Função de dispersão (saber onde vai inserir na tabela)
int dispersao_hash(int cod_pac);

// Inserir paciente com posição consecutiva livre
int inserir(TB_HASH tabela, Paciente paciente);

// Buscar com posição consecutiva livre
Paciente* busca(TB_HASH tabela, int codigo_paciente);

// Função para mostrar a tabela hash
void imprimir_hash(TB_HASH tabela);

// Função para excluir elementos da tabela hash
int apagar(TB_HASH tabela, int cod_pac);

#endif