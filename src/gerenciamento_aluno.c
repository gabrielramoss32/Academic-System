#include<stdio.h>
#include "cadastro_turma.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_turma.h"

void menu_alunos (int opcao_acesso) {
    int opcao;
    do {
        printf("\n┌─────────────────────────────────────┐");
        printf("\nTurma atual: %dº ano %s\n", turmas[opcao_acesso].serie, turmas[opcao_acesso].turma);
        printf("Alunos: %d\n", turmas[opcao_acesso].qtd_alunos);
        printf("\n - Selecione a opção desejada: \n");
        printf("[1] Cadastrar aluno\n");
        printf("[2] Editar aluno\n");
        printf("[3] Lançar notas\n");
        printf("[4] Ver boletim\n");
        printf("[5] Listar alunos\n");
        printf("[6] Buscar aluno\n");
        printf("[7] Ver estatísticas da turma\n");
        printf("[8] Excluir aluno\n");
        printf("[9] Voltar ao menu\n");
        printf("└─────────────────────────────────────┘\n");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 9) {
            printf("Opção inválida, selecione uma opção existente");
        }
    } while (opcao != 9); //repete o menu ate o usuario querer sair
}