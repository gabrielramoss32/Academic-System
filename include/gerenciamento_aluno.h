#ifndef GERENCIAMENTO_ALUNO_H
#define GERENCIAMENTO_ALUNO_H
#define MAX_AVALIACOES 5
#include<stdbool.h>

typedef struct {
    int matricula; //Variável com a matrícula de cada aluno
    char nome[80]; //Nome de cada aluno, com limite de até 80 caracteres
    float notas[MAX_AVALIACOES]; //Vetor de notas de cada aluno, com o máximo de 5 notas
    bool boletim_disponivel; //Representa se cada aluno teve sua nota lançada ou não, impedindo que a pessoa veja o boletim sem o aluno sequer ter nota
} Aluno;

//"int opcao_acesso" = variável usada de parâmetro nas funções para indicar qual turma está sendo gerenciada

void menu_alunos(int opcao_acesso); //Função que lista todas as opções disponíveis do gerenciamento de alunos
void cadastro_alunos(int opcao_acesso); //Função para o cadastro dos alunos
void listar_alunos(int opcao_acesso); //Função para a listagem de todos os alunos daquela turma
void editar_alunos(int opcao_acesso); //Função para entrar na edição de alunos
void dados_editar_aluno(int opcao_edit, int opcao_acesso); //Função para decidir o que será editado do aluno
bool validar_matricula(int opcao_acesso, int indice_aluno, int matricula); //Função para validar matrícula, usada na edição e no cadastro
void excluir_aluno(int opcao_acesso); //Função para excluir alunos
void buscar_aluno(int opcao_acesso); //Função para buscar alunos
void busca_por_matricula(int opcao_acesso); //Função para busca de aluno por matrícula
void busca_por_nome(int opcao_acesso); //Função para busca de aluno por nome

#endif 