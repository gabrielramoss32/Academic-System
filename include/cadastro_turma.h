#ifndef CADASTRO_TURMA_H
#define CADASTRO_TURMA_H
#define MAX_TURMAS 10 //Quantidade de turmas que pode ser registrado no sistema
#define MAX_ALUNOS 35 //Quantidade de alunos que podem ser registrados
#include<stdbool.h>
#include "gerenciamento_aluno.h"

typedef struct {
    int serie;
    char turma;
    char turno[15];
    char disciplina[40];

    Aluno alunos[MAX_ALUNOS]; //vetor com os alunos, cada turma poderá ter ate 35 alunos
    int qtd_alunos; //variável das quantidades de alunos das turmas
    int qtd_avaliacoes; //variável das quantidades de avaliação de cada turma
    char nome_notas[MAX_AVALIACOES][35]; //vetor referente ao modelo de cada avaliação (trabalho, prova, etc)
    float valor_notas[MAX_AVALIACOES]; //variável referente ao valor de cada avaliação
    float media; //variável referente à média de cada turma
} Turma;

extern Turma turmas[MAX_TURMAS]; //define uma unica variável de turmas na memoria
extern int qtd_turmas; //variável para controlar o índice de turmas cadastradas
extern bool acesso_menu; //variavel para controlar a repetição do menu de turma

void turma_cadastro (bool professor1_cadastrado);
void menu_turma ();

#endif