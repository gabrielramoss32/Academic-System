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
        printf("[1] Cadastrar aluno\n");
        printf("[2] Editar aluno\n");
        printf("[3] Lançar notas\n");
        printf("[4] Ver boletim\n");
        printf("[5] Listar alunos\n");
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

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                if (turmas[opcao_acesso].qtd_alunos == 0) {
                    printf("\nNão há alunos para serem listados, cadastre um.\n");
                } else {
                    listar_alunos(opcao_acesso);
                }
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
    bool repetido; //variavel que controla se a matrícula foi repetida ou não

    printf("Insira o nome do aluno: ");
    getchar(); //come o enter do buffer
    fgets(turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].nome,
    sizeof(turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].nome), stdin); //registra o nome do aluno

    do {
        repetido = false;
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
        }

    } while 
    (turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula >= 1000000
    || turmas[opcao_acesso].alunos[turmas[opcao_acesso].qtd_alunos].matricula <= 99999 || repetido == true); //repete se a matricula nao tiver 6 digitos ou se for repetida

    printf("\n - Aluno nº %d/35 cadastrado, selecione a próxima opção: \n", turmas[opcao_acesso].qtd_alunos + 1); //avisa que o aluno foi cadastrado
    turmas[opcao_acesso].qtd_alunos++; //incrementação da quantidade de alunos registrados naquela turma
}

void listar_alunos (int opcao_acesso) {
    printf("\n┌─────────────────────────────────────┐");
    printf("\nAlunos do %dº ano %c:\n", turmas[opcao_acesso].serie, turmas[opcao_acesso].turma); //mostra a turma em que os alunos serão listados
    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
        printf("\n[%d] %s | Matrícula: %d\n", i, turmas[opcao_acesso].alunos[i].nome, turmas[opcao_acesso].alunos[i].matricula); //exibe o numero, nome e matricula do aluno
    }
    printf("└─────────────────────────────────────┘\n");
}