#include <stdio.h>
#include <stdlib.h>

#include "Turma.h"

// Inicializar a lista
void start_list(Lista *class){
    for(int i = 0; i < max-1; i++){
        class->turma[i].prox = i+1;
    }
    class->turma[max-1].prox = -1;
    class->inicio = -1;
    class->disponivel = 0;
}

// Liberar a lista
void release(Lista *class){
    free(class);
}

// Retornar a quantidade de elementos válidos da lista
int valid_elements(Lista *class){
    int i = class->inicio;
    int size = 0;

    while(i != -1){
        size++;
        i = class->turma[i].prox;
    }
    return size;
}

// Retornar se a lista está cheia
int list_full(Lista *class){
    if(class == NULL){
        return -1;
    }else{
        return (valid_elements(class) == max);
    }
}

// Retornar se a lista está vazia
int list_empyt(Lista *class){
    if(class == NULL){
        return -1;
    }else{
        return (valid_elements(class) == 0);
    }
}

// Exibir os elementos da lista
void print_elements(Lista *class){
    int i = class->inicio;
    while(i != -1){
        printf("\nCodigo: %d", class->turma[i].student.code);
        printf("\nNome: %s", class->turma[i].student.nome);
        printf("\nIdade: %d", class->turma[i].student.idade);
        i = class->turma[i].prox;
        printf("\n");
    }

}


// Obter no, verficar espaços disponíveis
int obterNo(Lista *class){
    int disp = class->disponivel;
    if(class->disponivel != -1){
        class->disponivel = class->turma[disp].prox;
    }
    return disp;
}

// Inserir um elemento na lista de forma ordenada
int insert_student(Lista *class, Aluno new_aluno){
    if(list_full(class) ==  max){
        return -1;
    }

    int i = class->inicio;
    int pos_insert = -1;
    while((i != -1) && new_aluno.code > class->turma[i].student.code){
        pos_insert = i;
        i = class->turma[i].prox;
    }
    
    // Verificar se existe um elemento igual na lista
    if((i != -1) && new_aluno.code == class->turma[pos_insert].student.code){
        return -1;
    }

    i = obterNo(class);
    class->turma[i].student = new_aluno;
    if(pos_insert == -1){
        class->turma[i].prox = class->inicio;
        class->inicio = i;
    } else{
        class->turma[i].prox = class->turma[pos_insert].prox;
        class->turma[pos_insert].prox = i;
    }
}

// Alocar no
void alocaNo(Lista *class, int i){
    class->turma[i].prox = class->disponivel;
    class->disponivel = i;
}

// Excluir um elemento da lista
int delete_student(Lista *class, int code){
    int i = class->inicio;
    int ant = -1;

    while(i != -1 && class->turma[i].student.code < code){
        ant = i;
        i = class->turma[i].prox;
    }

    if(i != -1 && class->turma[i].student.code != code){
        return -1;
    }

    if(ant == -1){
        class->inicio = class->turma[i].prox;
    }else{
        class->turma[ant].prox = class->turma[i].prox;
    }
    alocaNo(class, i);
    return 1;
}

// Buscar se o aluno existe com base no código de matrícula
int search_lista(Lista *class, int code){
    int i = class->inicio;
    while(i != -1 && class->turma[i].student.code < code){
        i = class->turma[i].prox;
    }
    if(i != -1 && class->turma[i].student.code == code){
        return i;
    } else{
        return -1;
    }
}

int altera_cod(Lista *class, int code, int new_code){
    Aluno new_value;
    int i = search_lista(class, code);
    if(i == -1){
        return -1;
    }
    
    new_value = class->turma[i].student;
    delete_student(class, code);
    new_value.code = new_code;
    insert_student(class, new_value);
    return 1;
}
