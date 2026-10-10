#ifndef GERENCIAMENTO_AVALIACOES_H
#define GERENCIAMENTO_AVALIACOES_H
#include "cadastro_turma.h"

void acessar_avaliacoes(int opcao_acesso); //função usada para definir se o usuário vai cadastrar ou editar as avaliações
void definir_avaliacoes(int opcao_acesso); //função usada para cadastrar as avaliações daquela turma
void editar_avaliacoes(int opcao_acesso, bool av_cadastrada[opcao_acesso]); //função usada para editar as avaliações daquela turma
void editar_nome_avaliacao (int opcao_acesso); //função usada para editar o nome da avaliação 
void editar_nota_avaliacao (int opcao_acesso); //função usada para editar a nota da avaliação
void listar_avaliacoes(int opcao_acesso, bool av_cadastrada[opcao_acesso]); //função usada para listar todas as avalições daquela turma

extern bool av_cadastrada[MAX_TURMAS]; //vetor booleano que controla se cada turma já teve sua avaliação cadastrada

#endif