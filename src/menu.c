#include<stdio.h>
#include<windows.h>
#include "menu.h" 
#include "professor_cadastro.h"

void menu_inicial () {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada

    //Raiz do projeto: 1ª etapa a ser chamada

    int opcao;
    printf("┌───────SISTEMA ACADÊMICO───────┐\n");
    printf("Selecione o que você deseja:\n");
    printf("[1] Se cadastrar\n");
    printf("[2] Cadastrar turmas\n");
    printf("[3] Sair\n");
    printf("└───────────────────────────────┘\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            cadastro_professor();
            break;
        case 2:
            break;
        case 3:
            printf("Obrigado por acessar o sistema!");
            break;
        default:
            printf("Opção inválida!");
    }
}