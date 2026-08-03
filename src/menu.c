#include<stdio.h>
#include<windows.h>
#include "menu.h" 
#include "professor_cadastro.h"
#include "cadastro_turma.h"

void menu_inicial () {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada

    //Raiz do projeto: 1ª etapa a ser chamada

    int opcao; //opcao inicial do switch case

    printf("\n┌───────SISTEMA ACADÊMICO───────┐\n");
    printf("\n- Selecione o que você deseja:\n");
    printf("\n[1] Se cadastrar\n");
    printf("[2] Cadastrar turmas\n");
    printf("[3] Sair\n");
    printf("└───────────────────────────────┘\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            cadastro_professor(); //FUNÇÃO PRONTA E TESTADA
            break;
        case 2:
            turma_cadastro(professor1.cadastrado); //FUNÇÃO PRONTA E TESTADA
            break;
        case 3:
            printf("Obrigado por acessar o sistema.");
            break;
        default: //para numeros diferentes dos selecionados
            printf("Opção inválida, selecione uma opção existente.\n");
            menu_inicial();
    }
}