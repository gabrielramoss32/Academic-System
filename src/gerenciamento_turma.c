#include<stdio.h>
#include "cadastro_turma.h"
#include "gerenciamento_turma.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_avaliacoes.h"

void acessar_turma () {
    int opcao_acesso; //Variável para controlar o acesso das turmas

    if (qtd_turmas > 0) {
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Selecione qual turma deseja acessar: \n");
            for (int i = 0; i < qtd_turmas; i++) { //Realiza a listagem de todas as turmas
                printf("\nTurma Nº%d\n", i+1);
                printf("Série: %dº ano %c\n", turmas[i].serie, turmas[i].turma);
                printf("Turno: %s\n", turmas[i].turno);
                printf("Disciplina: %s", turmas[i].disciplina);
                printf("Digite %d para acessar.\n", i);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao_acesso);
            if (opcao_acesso >= 0 && opcao_acesso < qtd_turmas) {
                menu_alunos(opcao_acesso);
            } else {
                printf("\nOpção inválida, selecione uma turma existente.\n");
            }
        } while (opcao_acesso < 0 || opcao_acesso >= qtd_turmas); //repete o menu caso a turma inserida seja inválida
    } else {
        printf("\nNão há turmas para acessar, cadastre uma.\n");
    }
}

void editar_turma () {
    int opcao_edit; //Opção do switch case para decidir qual turma será editada

    if (qtd_turmas > 0) { //Verifica se existem turmas
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Selecione qual turma deseja editar: \n");
            for (int i = 0; i < qtd_turmas; i++) {
                printf("\nTurma de %s", turmas[i].disciplina);
                printf("Série: %dº ano %c | %s\n", turmas[i].serie, turmas[i].turma, turmas[i].turno);
                printf("Digite %d para editar.\n", i);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao_edit);
            if (opcao_edit >= 0 && opcao_edit < qtd_turmas) {
                dados_editar_turma(opcao_edit); //Chama a função de editar dados da turma e passa o índice da turma a ser editada
            } else {
                printf("\nOpção inválida, selecione uma turma existente.\n");
            }
        } while (opcao_edit < 0 || opcao_edit >= qtd_turmas); //Repete o menu caso a opção não seja nenhuma das turmas
    } else {
        printf("\nNão há turmas para editar, cadastre uma.\n");
    }
}

void dados_editar_turma (int opcao_edit) {
    int opcao;

    do {
        printf("\n- Selecione a opção desejada:\n");
        printf("[1] Série\n");
        printf("[2] Turma\n");
        printf("[3] Turno\n");
        printf("[4] Matéria\n");
        printf("[5] Voltar ao menu\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a nova série: ");
                scanf("%d", &turmas[opcao_edit].serie);
                printf("\nSérie alterada.\n");
                break;
            case 2:
                printf("Digite a nova turma: ");
                scanf(" %c", &turmas[opcao_edit].turma);
                printf("\nTurma alterada.\n");
                break;
            case 3:
                printf("Digite o novo turno: ");
                scanf("%s", turmas[opcao_edit].turno);
                printf("\nTurno alterado.\n");
                break;
            case 4:
                printf("Digite a nova matéria: ");
                getchar();
                fgets(turmas[opcao_edit].disciplina, sizeof(turmas[opcao_edit].disciplina), stdin);
                printf("\nMatéria alterada.\n");
                break;
            case 5:
                break;
            default:
                printf("Opção inválida, selecione uma opção existente.");
        }
    } while (opcao != 5);
}

void excluir_turma() {

    int opcao;
    char confirm; //Variável de confirmação da exclusão
    if (qtd_turmas > 0) {
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Selecione qual turma deseja excluir: \n");
            for (int i = 0; i < qtd_turmas; i++) {
                printf("\nTurma Nº%d\n", i+1);
                printf("Série: %dº ano %c\n", turmas[i].serie, turmas[i].turma);
                printf("Turno: %s\n", turmas[i].turno);
                printf("Disciplina: %s", turmas[i].disciplina);
                printf("Digite %d para excluir.\n", i);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao);

            if (opcao >= 0 && opcao < qtd_turmas) {
                printf("\nDeseja realmente excluir essa turma? (S/N)\n");
                printf("Quantidade de turmas: %d >>> %d\n", qtd_turmas, qtd_turmas-1);
                scanf(" %c", &confirm);
                if (confirm == 'S' || confirm == 's') {
                    for (int i = 0; i < qtd_turmas - opcao - 1; i++) { //Desloca apenas a quantidade de turmas que tem para deslocar
                        turmas[opcao] = turmas[opcao + 1]; 
                        av_cadastrada[opcao] = av_cadastrada[opcao + 1];
                        opcao++; //Incrementa para que a próxima turma possa ser deslocada para a posição desejada
                    }
                    qtd_turmas--; //Retira uma quantidade de turma cadastrada
                    opcao = 0;
                    printf("\nExclusão bem sucedida, você retornará ao menu.\n");
                } else {
                    printf("\nExclusão cancelada, você retornará ao menu.\n");
                }
            } else {
                printf("\nOpção inválida, selecione uma turma existente.\n");
            }
        } while (opcao < 0 || opcao > qtd_turmas); //repete o menu caso a turma selecionada nao exista
    } else {
        printf("\nNão há turmas para excluir, selecione outra opção ou cadastre uma turma.\n");
    }
}