#include<stdio.h>
#include<stdbool.h>
#include "gerenciamento_notas.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_avaliacoes.h"
#include "cadastro_turma.h"

void lancar_notas (int opcao_acesso, bool av_cadastrada[opcao_acesso]) {
    int opcao_nota;

    if (av_cadastrada[opcao_acesso] == true && turmas[opcao_acesso].qtd_alunos > 0) { //verifica se as avaliações naquela turma já foram cadastradas e se há  alunos naquela turma
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Digite o número do aluno que terá sua nota lançada:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
                printf("[%d] %s", i, turmas[opcao_acesso].alunos[i].nome);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao_nota);
            if (opcao_nota >= 0 && opcao_nota < turmas[opcao_acesso].qtd_alunos) {
                preencher_notas(opcao_acesso, opcao_nota);
            } else {
                printf("\nOpção inválida, selecione um aluno existente");
            }
        } while (opcao_nota < 0 || opcao_nota >= turmas[opcao_acesso].qtd_alunos); 
    } else {
        printf("\nNão foi possível acessar o lançamento de notas, verifique se há alunos naquela turma e se você cadastrou avaliações.\n");
    } 
}

void preencher_notas(int opcao_acesso, int opcao_nota) {

    printf("\n- Insira as notas de %s", turmas[opcao_acesso].alunos[opcao_nota].nome);
    printf("Certifique-se que a nota esteja entre 0 e o valor da avaliação.\n");

    for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
        do {
            printf("\nInsira a nota de: %s [%.2f]: ", turmas[opcao_acesso].nome_notas[i], turmas[opcao_acesso].valor_notas[i]);
            scanf("%f", &turmas[opcao_acesso].alunos[opcao_nota].notas[i]);
            if (turmas[opcao_acesso].alunos[opcao_nota].notas[i] < 0 || turmas[opcao_acesso].alunos[opcao_nota].notas[i] > turmas[opcao_acesso].valor_notas[i]) {
                printf("\nA nota deve ser maior que 0 e menor ou igual ao valor da avaliação.\n");
            } else {
                printf("Nota lançada.\n");
            }
        } while (turmas[opcao_acesso].alunos[opcao_nota].notas[i] < 0 || 
        turmas[opcao_acesso].alunos[opcao_nota].notas[i] > turmas[opcao_acesso].valor_notas[i]); //repete o menu se a nota for inválida (< 0 ou > do que o valor daquela avaliação)
    }
    printf("\n> Notas lançadas, confira o boletim do aluno e lance novamente as notas se quiser editar alguma nota.\n");
} 