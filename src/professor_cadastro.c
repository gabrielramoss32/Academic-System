#include<stdio.h>
#include<windows.h>
#include "professor_cadastro.h"
#include "cadastro_turma.h"

Professor professor1 = {
    .cadastrado = false //professor global definido como sem cadastro
};

Professor professor1; //Variável professor1, declarada pela definição de professor na struct declarada

void cadastro_professor () {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada

    int opcao; //opcao do switch case de cadastrar turma ou sair

    printf("Insira seu ID: ");
    scanf("%d", &professor1.id);
    while (professor1.id < 1000 || professor1.id > 9999)  { //verificação de digitos do ID
        printf("Seu ID deve ter obrigatoriamente 4 dígitos, insira-o novamente: ");
        scanf("%d", &professor1.id);
    }

    printf("Digite sua idade: ");
    scanf("%d", &professor1.idade);
    while (professor1.idade < 21) { //verificação de idade
        printf("Idade muito baixa, insira uma idade maior do que 20 anos: \n");
        scanf("%d", &professor1.idade);
    }

    printf("Digite o seu nome: ");
    getchar(); //come o enter do buffer
    fgets(professor1.nome, sizeof(professor1.nome), stdin);

    printf("Digite a sua formação: ");
    getchar(); //come o enter do buffer
    fgets(professor1.formacao, sizeof(professor1.formacao), stdin);

    printf("Digite o nome da escola em que você é professor: ");
    getchar();  //come o enter do buffer
    fgets(professor1.escola, sizeof(professor1.escola), stdin);

    printf("\nCadastro realizado! Seja bem-vindo %s\n", professor1.nome);

    professor1.cadastrado = true; //o sistema recebe a informação de que o professor se cadastrou

    do {
        printf("\n┌─────────────────────────────┐\n");
        printf("\n- Selecione o que você deseja: \n");
        printf("\n[1] Cadastrar turma\n");
        printf("[2] Sair\n");
        printf("└─────────────────────────────┘\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                turma_cadastro(professor1.cadastrado);
                break;
            case 2:
                printf("Obrigado pelo seu cadastro!");
                break;
            default:
                printf("Opção inválida, selecione uma opção existente.\n");
            }
    } while (opcao != 1 && opcao != 2);
}