#ifndef CADASTRO_TURMA_H
#define CADASTRO_TURMA_H
#define MAX_TURMAS 10 //Quantidade de turmas que pode ser registrado no sistema
#define MAX_ALUNOS 35 //Quantidade de alunos que podem ser registrados por turma
#include<stdbool.h>
#include "gerenciamento_aluno.h"

typedef struct {
    int serie;
    char turma;
    char turno[15];
    char disciplina[40];
    //Informações que compõem a turma em si

    Aluno alunos[MAX_ALUNOS]; //Vetor com os alunos, cada turma poderá ter ate 35 alunos
    int qtd_alunos; //Variável das quantidades de alunos das turmas
    int qtd_avaliacoes; //Variável das quantidades de avaliação de cada turma
    char nome_notas[MAX_AVALIACOES][35]; //Vetor referente ao modelo de cada avaliação (trabalho, prova, etc)
    float valor_notas[MAX_AVALIACOES]; //Variável referente ao valor de cada avaliação
    float media; //Variável referente à média de cada turma
    //Informações adicionais que compõem a turma
} Turma;

extern Turma turmas[MAX_TURMAS]; //Define uma unica variável de turmas na memória, para todo o arquivo reconhecer
extern int qtd_turmas; //Variável para controlar o índice de turmas cadastradas
extern bool acesso_menu; //Variável para controlar a repetição do menu de turma

void turma_cadastro (bool professor1_cadastrado);
void menu_turma ();

#endif