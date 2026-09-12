#include<stdio.h>
#include<stdbool.h>
#include "cadastro_turma.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_turma.h"

void menu_alunos (int opcao_acesso) {
    int opcao;
    do {
        printf("\n┌─────────────────────────────────────┐");
        printf("\nTurma atual: %dº ano %c\n", turmas[opcao_acesso].serie, turmas[opcao_acesso].turma);
        printf("Alunos: %d\n", turmas[opcao_acesso].qtd_alunos);
        printf("\n - Selecione a opção desejada:\n");
        printf("[1] Cadastrar aluno\n"); //pronto
        printf("[2] Editar aluno\n"); //pronto
        printf("[3] Lançar notas\n");
        printf("[4] Ver boletim\n");
        printf("[5] Listar alunos\n"); //pronto
        printf("[6] Buscar aluno\n");
        printf("[7] Ver estatísticas da turma\n");
        printf("[8] Excluir aluno\n");
        printf("[9] Voltar ao menu\n");
        printf("└─────────────────────────────────────┘\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (turmas[opcao_acesso].qtd_alunos >= MAX_ALUNOS) { //verifica se a turma ja esta cheia
                    printf("\nQuantidade de alunos excedida por turma, exclua um caso queira cadastrar.\n");
                } else {
                    cadastro_alunos(opcao_acesso);
                }
                break;
            case 2:
                editar_alunos(opcao_acesso);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                listar_alunos(opcao_acesso);
                break;
            case 6:

                break;
            case 7:

                break; 
            case 8:

                break; 
            case 9:
                break;
            default:
                printf("\nOpção inválida, selecione uma opção existente.\n");         
        }
    } while (opcao != 9); //repete o menu ate o usuario querer sair
}

void cadastro_alunos (int opcao_acesso) {
    bool repetido, irregular; //variáveis que controlam a validação da matrícula

    printf("Insira o nome do aluno: ");
    getchar();
    fgets(turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].nome,
    sizeof(turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].nome), stdin); //registra o nome do aluno

    do {
        repetido = false;
        irregular = false;
        printf("Digite a matrícula do aluno (6 dígitos): ");
        scanf("%d", &turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula); //registra a matriula do aluno

        for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { //percorre todos os alunos registrados
            if (turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula == 
            turmas[opcao_acesso].alunos[i].matricula) { //verifica se aquele numero de matricula ja foi registrado
                printf("\nNúmero de matrícula já registrado anteriormente, insira um número disponível.\n");
                repetido = true; //confirma que o ultimo numero de matricula registrado foi repetido
                break; //sai do laço caso seja encontrado um valor repetido
            } //se nao encontrar matricula repetida, a variavel registradora continua como false
        }

        if (turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula >= 1000000 //verifica se a matricula tem 6 dígitos
        || turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula <= 99999) {
            printf("\nO número de matrícula deve conter obrigatoriamente 6 dígitos.\n");
            irregular = true;
        }

    } while (irregular == true || repetido == true); //repete se a matricula nao tiver 6 digitos ou se for repetida

    printf("\n - Aluno nº %d/35 cadastrado, selecione a próxima opção: \n", turmas[opcao_acesso].qtd_alunos + 1); //avisa que o aluno foi cadastrado
    turmas[opcao_acesso].qtd_alunos++; //incrementação da quantidade de alunos registrados naquela turma
}

void listar_alunos (int opcao_acesso) {
    if (turmas[opcao_acesso].qtd_alunos == 0) {
        printf("\nNão há alunos para serem listados, cadastre um.\n");
    } else {
        printf("\n┌─────────────────────────────────────┐");
        printf("\nAlunos do %dº ano %c:\n", turmas[opcao_acesso].serie, turmas[opcao_acesso].turma); //mostra a turma em que os alunos serão listados
        for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
            printf("\n[%d] %s | Matrícula: %d\n", i, turmas[opcao_acesso].alunos[i].nome, turmas[opcao_acesso].alunos[i].matricula); //exibe o numero, nome e matricula do aluno
        }
        printf("└─────────────────────────────────────┘\n");
    }
}

void editar_alunos (int opcao_acesso) {
    int opcao_edit; //opção para decidir qual aluno será editado

    if (turmas[opcao_acesso].qtd_alunos > 0) { //verifica se tem alunos para serem editados
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Digite o número do aluno que quer editar:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { //lista todos os alunos
                printf("\n[%d] %s | Matrícula: %d\n", i, turmas[opcao_acesso].alunos[i].nome, turmas[opcao_acesso].alunos[i].matricula);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao_edit);
            if (opcao_edit >= 0 && opcao_edit < turmas[opcao_acesso].qtd_alunos) {
                dados_editar_aluno(opcao_edit, opcao_acesso);
            } else {
                printf("\nOpção inválida, selecione um aluno existente");
            }
        } while (opcao_edit < 0 || opcao_edit >= turmas[opcao_acesso].qtd_alunos); //repete o menu caso o aluno selecionado não exista
    } else {
        printf("\nNão há aluno para ser editado, cadastre um.\n");
    }
}

void dados_editar_aluno (int opcao_edit, int opcao_acesso) {
    int opcao;

    do {
        printf("\n- Selecione o que deseja editar:\n");
        printf("[1] Nome do aluno\n");
        printf("[2] Matrícula do aluno\n");
        printf("[3] Voltar ao menu\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo nome do aluno: ");
                getchar();
                fgets(turmas[opcao_acesso].alunos[opcao_edit].nome,
                sizeof(turmas[opcao_acesso].alunos[opcao_edit].nome), stdin); //pega o novo nome do aluno
                printf("\nNome alterado.\n");
                break;
            case 2:
                bool repetido, irregular;
                do {
                    repetido = false;
                    irregular = false;
                    printf("Digite a nova matrícula do aluno (6 dígitos): ");
                    scanf("%d", &turmas[opcao_acesso].alunos[opcao_edit].matricula); 
                    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { 
                        if (turmas[opcao_acesso].alunos[opcao_edit].matricula == turmas[opcao_acesso].alunos[i].matricula) { 
                            printf("\nNúmero de matrícula já registrado anteriormente, insira um número disponível.\n");
                            repetido = true; 
                            break; 
                        }
                    }
                    if (turmas[opcao_acesso].alunos[opcao_edit].matricula >= 1000000 || turmas[opcao_acesso].alunos[opcao_edit].matricula <= 99999) {
                        printf("\nO número de matrícula deve conter obrigatoriamente 6 dígitos.\n");
                        irregular = true;
                    }
                } while (irregular == true || repetido == true);
                printf("\nMatrícula alterada.\n");
                break;
            case 3:
                break;
            default:
                printf("Opção inválida, selecione uma opção existente.");
        }
    } while (opcao != 3); //repete enquanto o usuario nao quiser sair
}