#ifndef CADASTRO_TURMA_H
#define CADASTRO_TURMA_H
#define MAX_TURMAS 10 //Quantidade de turmas que pode ser registrado no sistema
#include<stdbool.h>

typedef struct {
    int serie;
    char turma;
    char turno[15];
    char disciplina[40];
} Turma; //struct com as informações da turma

//cadastro_turma.c 

extern Turma turmas[MAX_TURMAS]; //define uma unica variável de turmas na memoria, localizada em
extern int qtd_turmas; //variável para controlar o índice de turmas cadastradas
extern int contTurma; //variável para informar a quantidade de turmas cadastradas ao usuário

void turma_cadastro (bool professor1_cadastrado);

#endif