#ifndef GERENCIAMENTO_ALUNO_H
#define GERENCIAMENTO_ALUNO_H
#define MAX_AVALIACOES 5

typedef struct {
    int matricula; //variável com a matrícula de cada aluno
    char nome[80]; //nome de cada aluno, com limite de até 80 caracteres
    float notas[MAX_AVALIACOES]; //vetor de notas de cada aluno, com o máximo de 5 notas (pode mudar depois)
} Aluno;

//"int opcao_acesso" = variável usada de parâmetro nas funções para indicar qual turma está sendo gerenciada

void menu_alunos(int opcao_acesso); //função que lista todas as opções disponíveis do gerenciamento de alunos
void cadastro_alunos(int opcao_acesso); //função para o cadastro dos alunos
void listar_alunos(int opcao_acesso); //função para a listagem de todos os alunos daquela turma
void editar_alunos(int opcao_acesso); //função para entrar na edição de alunos
void dados_editar_aluno(int opcao_edit, int opcao_acesso); //função para decidir o que será editado do aluno (em breve terão as notas)
void excluir_aluno(int opcao_acesso); //função para excluir alunos (rever la na frente para excluir as notas também)

#endif 