#ifndef CADASTRO_TURMA_H
#define CADASTRO_TURMA_H
#include<stdbool.h>

typedef struct {
    int serie;
    char turma;
    char turno[15];
    char disciplina[40];
} Turma; //struct com as informações da turma

void turma_cadastro (bool professor1_cadastrado);

#endif