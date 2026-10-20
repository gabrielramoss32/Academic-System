#ifndef GERENCIAMENTO_NOTAS_H
#define GERENCIAMENTO_NOTAS_H
#include "cadastro_turma.h"

typedef struct {
    char nome[80];
    float media_final;
} Classificacao; //Struct responsável por copiar os dados dos alunos para a ordenação 

void lancar_notas (int opcao_acesso, bool av_cadastrada[MAX_TURMAS]); //Função usada para validar e liberar o lançamento de notas dos alunos
void preencher_notas(int opcao_acesso, int opcao_nota); //Função usada para preencher a nota do aluno selecionado
void ver_boletim (int opcao_acesso); //Função usada para visualizar o boletim do aluno
void ver_estatisticas (int opcao_acesso); //Função usada para o menu de selecionar estatísticas
void crescente_decrescente(int opcao_acesso, bool crescente); //Função usada para exibir média dos alunos na ordem que for escolhida na hora
void aprovados_reprovados (int opcao_acesso); //Função usada para visualizar os aprovados e reprovados
void maior_menor_nota_av (int opcao_acesso); //Função usada para visualizar a maior e menor nota de cada avaliação

#endif