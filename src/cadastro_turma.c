#include<stdio.h>
#include<stdbool.h>
#include "cadastro_turma.h"
#include "menu.h"
#include "professor_cadastro.h"
#include "gerenciamento_turma.h"
#include "gerenciamento_avaliacoes.h"

Turma turmas[MAX_TURMAS]; //Variável turmas, declarada pelo typedef da struct turma
int qtd_turmas = 0; //Define o tamanho atual da quantidade de turmas
bool acesso_menu = true; //Variável que abre o menu apenas uma vez, impedindo recorrência indesejada

void turma_cadastro (bool professor1_cadastrado) {

    if (!professor1_cadastrado) { //verifica se o professor está cadastrado
        printf("Você ainda não realizou o seu cadastro, realize ele para cadastrar as suas turmas.\n");
        menu_inicial();
    } else {
        do {
            printf("Insira a série da turma (6º, 7º, 8º): ");
            scanf("%d", &turmas[qtd_turmas].serie);
            if (turmas[qtd_turmas].serie <= 0 || turmas[qtd_turmas].serie > 9) {
                printf("A série deve ser maior que 0 e menor ou igual a 9.\n");
            }
        } while (turmas[qtd_turmas].serie <= 0 || turmas[qtd_turmas].serie > 9);

        printf("Digite a turma (A, B, C): ");
        scanf(" %c", &turmas[qtd_turmas].turma);

        printf("Digite qual turno você ministra essa turma: ");
        scanf("%s", turmas[qtd_turmas].turno);

        printf("Digite qual matéria você ministra nessa turma: ");
        getchar();
        fgets(turmas[qtd_turmas].disciplina, sizeof(turmas[qtd_turmas].disciplina), stdin);

        printf("\n- Turma nº %d/%d cadastrada, selecione a próxima opção: \n", qtd_turmas + 1, MAX_TURMAS);

        turmas[qtd_turmas].qtd_alunos = 0; //zera ou define a quantidade de alunos daquela turma como zero
        av_cadastrada[qtd_turmas] = false; //define como false que aquela turma teve avaliação cadastrada (impede de acessar as avaliações de uma turma que foi excluída)
        qtd_turmas++; //Incrementação da quantidade de turma atual (limite: 10)

        if (acesso_menu) { //chama esse menu somente uma vez
            acesso_menu = false; //fecha qualquer possibilidade de abrir o menu novamente
            menu_turma();
        }
    }
}

void menu_turma () {
    int opcao;
    do {
        printf("\n┌─────────────────────────────┐\n");
        printf("[1] Cadastrar nova turma\n");
        printf("[2] Editar turma\n");
        printf("[3] Acessar turma\n");
        printf("[4] Excluir turma\n");
        printf("[5] Sair\n");
        printf("└─────────────────────────────┘\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (qtd_turmas >= MAX_TURMAS) {
                    printf("Quantidade de turmas excedida, selecione uma opção existente.\n");
                } else {
                    turma_cadastro(professor1.cadastrado); //chama novamente para cadastrar mais turma
                }
                break;
            case 2:
                editar_turma();
                break;
            case 3:
                acessar_turma();
                break;
            case 4:
                excluir_turma();
                break;
            case 5:
                printf("Agradecemos pelo cadastro da turma.");
                break;
            default:
                printf("Opção inválida, selecione uma opção existente: \n");
            } 
    } while (opcao != 5);
}