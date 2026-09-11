#ifndef GERENCIAMENTO_ALUNO_H
#define GERENCIAMENTO_ALUNO_H
#define MAX_AVALIACOES 5

typedef struct {
    int matricula; //variavel com a matricula de cada aluno
    char nome[80]; //nome de cada aluno, com limite de ate 80 caracteres
    float notas[MAX_AVALIACOES]; //vetor de notas de cada aluno, com o maximo de 5 notas
} Aluno;

void menu_alunos(int opcao_acesso);
void cadastro_alunos(int opcao_acesso); //função para o cadastro dos alunos
void listar_alunos(int opcao_acesso); //função para a listagem de todos os alunos daquela turma
void editar_alunos(int opcao_acesso); //função para entrar na edição de alunos

#endif 