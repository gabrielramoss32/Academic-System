#ifndef GERENCIAMENTO_NOTAS_H
#define GERENCIAMENTO_NOTAS_H
#include "cadastro_turma.h"

void lancar_notas (int opcao_acesso, bool av_cadastrada[MAX_TURMAS]); //função usada para validar e liberar o lançamento de notas dos alunos
void preencher_notas(int opcao_acesso, int opcao_nota); //função usada para preencher a nota do aluno selecionado
void ver_boletim (int opcao_acesso); //função usada para visualizar o boletim do aluno
void ver_estatisticas (int opcao_acesso); //função usada para o menu de selecionar estatísticas
void aprovados_reprovados (int opcao_acesso); //função usada para visualizar os aprovados e reprovados
void maior_menor_nota_av (int opcao_acesso); //função usada para visualizar a maior e menor nota de cada avaliação

#endif