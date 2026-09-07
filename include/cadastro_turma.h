#ifndef CADASTRO_TURMA_H
#define CADASTRO_TURMA_H
#define MAX_TURMAS 10 //Quantidade de turmas que pode ser registrado no sistema
#include<stdbool.h>
#include "gerenciamento_aluno.h"
#define MAX_ALUNOS 35

typedef struct {
    int serie;
    char turma;
    char turno[15];
    char disciplina[40];

    Aluno alunos[MAX_ALUNOS]; //Vetor com os alunos, cada turma podera ter ate 35 alunos
    int qtd_alunos; //variavel das quantidade de alunos das turmas
} Turma; //struct com as informações da turma

extern Turma turmas[MAX_TURMAS]; //define uma unica variável de turmas na memoria, localizada em
extern int qtd_turmas; //variável para controlar o índice de turmas cadastradas
extern bool acesso_menu; //variavel para controlar a repetição do menu de turma

void turma_cadastro (bool professor1_cadastrado);
void menu_turma ();

#endif