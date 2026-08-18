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
    int opcao_edit; //opcao do switch case para decidir qual turma sera editada

    do {
        printf("\n┌─────────────────────────────────────┐\n");
        printf("- Selecione qual turma deseja editar: \n");
        for (int i = 0; i < qtd_turmas; i++) { //lista todas as turmas disponíveis para edição
            printf("\nTurma de %s", turmas[i].disciplina);
            printf("Série: %dº ano %c | %s\n", turmas[i].serie, turmas[i].turma, turmas[i].turno);
            printf("Digite %d para editar.\n", i);
        }
            scanf("%d", &opcao_edit);
            if (opcao_edit >= 0 && opcao_edit <= qtd_turmas) {
                dados_editar_turma(opcao_edit); //chama a função de editar dados da turma e passa o indice da turma a ser editada
            } else {
                printf("\nOpção inválida, selecione uma turma existente.\n");
            }
    } while (opcao_edit < 0 || opcao_edit > qtd_turmas); //repete o menu caso a opção nao seja nenhuma das turmas
}

void dados_editar_turma (int opcao_edit) {
    int opcao;

    do {
        printf("\n- Selecione a opção desejada:\n");
        printf("[1] Série\n");
        printf("[2] Turma\n");
        printf("[3] Turno\n");
        printf("[4] Matéria\n");
        printf("[5] Editar outra turma\n");
        printf("[6] Voltar ao menu\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a nova série: ");
                scanf("%d", &turmas[opcao_edit].serie); //a serie antiga recebe a nova
                break;
            case 2:
                printf("Digite a nova turma: ");
                scanf(" %c", &turmas[opcao_edit].turma); //a turma antiga recebe a nova
                break;
            case 3:
                printf("Digite o novo turno: ");
                scanf("%s", turmas[opcao_edit].turno); //o turno antigo recebe o novo
                break;
            case 4:
                printf("Digite a nova matéria: ");
                getchar(); //come o enter do buffer
                fgets(turmas[opcao_edit].disciplina, sizeof(turmas[opcao_edit].disciplina), stdin); //a disciplina antiga recebe a nova
                break;
            case 5:
                editar_turma();
                break;
            case 6:
                menu_turma();
                break;
            default:
                printf("Opção inválida, selecione uma opção existente.");
        }
    } while (opcao != 6); //repete o menu, exceto se ele quiser voltar para o anterior
}

void excluir_turma() {

    int opcao;
    char confirm; //variavel de confirmação da exclusão
    if (qtd_turmas > 0) {
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Selecione qual turma deseja excluir: "); //lista todas as turmas disponíveis para exclusão
            for (int i = 0; i < qtd_turmas; i++) {
                printf("\nTurma Nº%d\n", i+1);
                printf("Série: %dº ano %c\n", turmas[i].serie, turmas[i].turma);
                printf("Turno: %s\n", turmas[i].turno);
                printf("Disciplina: %s", turmas[i].disciplina);
                printf("Digite %d para excluir.\n", i);
            }
            printf("\n└─────────────────────────────────────┘\n");
            scanf("%d", &opcao);

            if (opcao >= 0 && opcao <= qtd_turmas) {
                printf("\nDeseja realmente excluir essa turma? (S/N)\n");
                scanf(" %c", &confirm);
                if (confirm == 'S' || confirm == 's') {
                    for (int i = 0; i < qtd_turmas; i++) {
                        turmas[opcao] = turmas[opcao + 1]; 
                        opcao++; //incrementa para fazer isso com a próxima turma
                }
                    qtd_turmas--; //retira uma quantidade de turma cadastrada
                    printf("\nExclusão bem sucedida, você retornará ao menu.\n");
                    menu_turma();
                } else {
                    printf("\nExclusão cancelada, você retornará ao menu.\n");
                    menu_turma(); //chama o menu novamente caso ele não queira excluir a turma
                }
            } else {
                printf("\nOpção inválida, selecione uma turma existente.\n");
            }
        } while (opcao < 0 || opcao > qtd_turmas); //repete o menu caso a turma selecionada nao exista
    } else {
        printf("\nNão há turmas para excluir, selecione outra opção ou cadastre uma turma.\n");
        menu_turma();
    }  
}