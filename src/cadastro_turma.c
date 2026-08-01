#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include "cadastro_turma.h"
#include "menu.h"
#include "professor_cadastro.h"

void turma_cadastro (bool professor1_cadastrado) {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada

    Turma turmas; //Variável turmas, declarada pelo typedef da struct turma

    if (!professor1_cadastrado) { //verifica se o professor está cadastrado
        printf("Você ainda não realizou o seu cadastro, realize ele para cadastrar as suas turmas.\n");
        menu_inicial();
    } else {
        printf("Insira a série da turma: (6º, 7º, 8º)");
        scanf("%d", &turmas.serie);

        printf("Digite a turma: (A, B, C)");
        scanf(" %c", &turmas.turma);

        printf("Digite qual turno você ministra essa turma: ");
        scanf("%s", turmas.turno);

        printf("Digite qual matéria você ministra nessa turma: ");
        getchar(); //come o enter do buffer
        fgets(turmas.disciplina, sizeof(turmas.disciplina), stdin);
    }
}