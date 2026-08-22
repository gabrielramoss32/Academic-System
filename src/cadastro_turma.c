#include<stdio.h>
#include<stdbool.h>
#include "cadastro_turma.h"
#include "menu.h"
#include "professor_cadastro.h"
#include "gerenciamento_turma.h"

Turma turmas[MAX_TURMAS]; //Variável turmas, declarada pelo typedef da struct turma
int qtd_turmas = 0; //Define o tamanho atual da quantidade de turmas;
bool acesso_menu = true;

void turma_cadastro (bool professor1_cadastrado) {

    if (!professor1_cadastrado) { //verifica se o professor está cadastrado
        printf("Você ainda não realizou o seu cadastro, realize ele para cadastrar as suas turmas.\n");
        menu_inicial();
    } else {
        printf("Insira a série da turma (6º, 7º, 8º): ");
        scanf("%d", &turmas[qtd_turmas].serie);

        printf("Digite a turma (A, B, C): ");
        scanf(" %c", &turmas[qtd_turmas].turma);

        printf("Digite qual turno você ministra essa turma: ");
        scanf("%s", turmas[qtd_turmas].turno);

        printf("Digite qual matéria você ministra nessa turma: ");
        getchar(); //come o enter do buffer
        fgets(turmas[qtd_turmas].disciplina, sizeof(turmas[qtd_turmas].disciplina), stdin);

        printf("\n- Turma nº %d/10 cadastrada, selecione a próxima opção: \n", qtd_turmas + 1);
        qtd_turmas++; //Incrementação da quantidade de turma atual
        if (acesso_menu) { //chama esse menu somente uma vez
            acesso_menu = false; //fecha qualquer possibilidade de abrir o menu novamente
            menu_turma();
        }
    }
}

void menu_turma () {
    int opcao; //opção do switch case para gerenciar turma
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
                    opcao = 0; //zera o switch de opçao e retorna o menu caso ele tente cadastrar apos o limite
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