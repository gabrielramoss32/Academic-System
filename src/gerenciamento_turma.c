#include<stdio.h>
#include<windows.h>
#include "cadastro_turma.h"
#include "gerenciamento_turma.h"

void acessar_turma () {
    printf("\n┌─────────────────────────────────────┐\n");
    printf("- Selecione qual turma deseja acessar: \n");
    //Realiza a listagem de todas as turmas
    for (int i = 0; i < qtd_turmas; i++) {
        printf("\nTurma Nº%d\n", i+1);
        printf("Série: %dº ano %c\n", turmas[i].serie, turmas[i].turma);
        printf("Turno: %s\n", turmas[i].turno);
        printf("Disciplina: %s", turmas[i].disciplina);
    }
    printf("\n└─────────────────────────────────────┘\n");
}

void editar_turma () {
    TurmaEdit turma_editada; //variavel local da struct de turma editada
    int opcao; //opcao do switch case para decidir qual turma sera editada

    do {
        printf("\n┌─────────────────────────────────────┐\n");
        printf("- Selecione qual turma deseja editar: \n");
        for (int i = 0; i < qtd_turmas; i++) {
            printf("Turma de %s\n", turmas[i].disciplina);
            printf("Série: %dº ano %c | %s", turmas[i].serie, turmas[i].turma, turmas[i].turno);
            printf("Digite %d para editar.", i);
        }
            scanf("%d", &opcao);
            if (opcao >= 0 && opcao <= qtd_turmas) {
                printf("- Selecione qual opção quer editar: ");
                //AQUI DEVERÁ TER A CHAMADA DE QUAL DADO DA TURMA EDITAR!!!!!!
            } else {
                printf("Opção inválida, selecione uma turma existente.");
            }
    } while (opcao < 0 || opcao > qtd_turmas); //repete o menu caso a opção nao seja nenhuma das turmas
}

void dados_editar_turma () {
    
}