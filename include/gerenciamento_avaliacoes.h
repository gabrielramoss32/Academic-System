#ifndef GERENCIAMENTO_AVALIACOES_H
#define GERENCIAMENTO_AVALIACOES_H
#include "cadastro_turma.h"

void acessar_avaliacoes(int opcao_acesso); //Função usada para definir se o usuário vai cadastrar ou editar as avaliações
void definir_avaliacoes(int opcao_acesso); //Função usada para cadastrar as avaliações daquela turma
void editar_avaliacoes(int opcao_acesso, bool av_cadastrada[MAX_TURMAS]); //Função usada para editar as avaliações daquela turma
void editar_nome_avaliacao (int opcao_acesso); //Função usada para editar o nome da avaliação 
void editar_nota_avaliacao (int opcao_acesso); //Função usada para editar a nota da avaliação
void listar_avaliacoes(int opcao_acesso, bool av_cadastrada[MAX_TURMAS]); //Função usada para listar todas as avalições daquela turma

extern bool av_cadastrada[MAX_TURMAS]; //Vetor booleano que controla se cada turma já teve sua avaliação cadastrada

#endif