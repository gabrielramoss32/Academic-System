#include<stdio.h>
#include<windows.h>
#include "professor_cadastro.h"

typedef struct {
    int id;
    int idade;
    char nome[100];
    char formacao[50];
    char disciplina[30];
    char escola[100];
} Professor; 
 
void cadastro_professor () {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada

    Professor professor1; //Variável professor1, declarada pela definição de professor na struct declarada

    printf("Insira seu ID: ");
    scanf("%d", &professor1.id);

    printf("Digite sua idade: ");
    scanf("%d", &professor1.idade);
    while (professor1.idade < 21) {
        printf("Idade muito baixa, insira uma idade maior do que 20 anos: \n");
        scanf("%d", &professor1.idade);
    }

    printf("Digite o seu nome: ");
    getchar();
    fgets(professor1.nome, sizeof(professor1.nome), stdin);

    printf("Digite a sua formação: ");
    scanf("%s", professor1.formacao);

    printf("Digite a disciplina que você ministra: ");
    scanf("%s", professor1.disciplina);

    printf("Digite o nome da escola em que você é professor: ");
    getchar();
    fgets(professor1.escola, sizeof(professor1.escola), stdin);

    printf("\nCadastro realizado! Seja bem-vindo %s", professor1.nome);
}