#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "gerenciamento_avaliacoes.h"
#include "gerenciamento_aluno.h"
#include "cadastro_turma.h"

bool av_cadastrada[MAX_TURMAS] = {false}; //inicializa que todas as turmas não cadastraram avaliações

void acessar_avaliacoes(int opcao_acesso) {
    int opcao;

    do {
        printf("\n - Selecione o que você deseja:\n");
        printf("[1] Definir avaliações\n");  
        printf("[2] Editar avaliações\n");
        printf("[3] Listar avaliações\n");
        printf("[4] Voltar ao menu\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                definir_avaliacoes(opcao_acesso);
                break;
            case 2:
                editar_avaliacoes(opcao_acesso, av_cadastrada);
                break;
            case 3:
                listar_avaliacoes(opcao_acesso, av_cadastrada);
                break;
            case 4:
                break;
            default:
                printf("\nOpção inválida, selecione uma opção existente.\n");       
        }
    } while (opcao != 4); //repete o menu até ele querer sair
}

void definir_avaliacoes(int opcao_acesso) {
    float soma_avaliacoes = 0.0; //variável da soma das notas, DEVE ser == 10

    printf("\nRegras de avaliações:\n");
    printf("1. Só são permitidas cadastrar até %d avaliações;\n", MAX_AVALIACOES);
    printf("2. A soma de todas as avaliações deve ser igual a 10 pontos;\n");
    printf("3. Defina um nome para cada avaliação;\n");
    printf("4. Notas com partes fracionárias devem ser separadas com ponto ao invés de vírgula;\n");
    printf("5. A nota de cada avaliação deve ser maior que 0 e menor que 10.\n");
    do {
        printf("\n- Defina quantas avaliações a turma terá: ");
        scanf("%d", &turmas[opcao_acesso].qtd_avaliacoes); //irá registrar quantas avaliações aquela turma irá possuir

        if (turmas[opcao_acesso].qtd_avaliacoes < 1 || turmas[opcao_acesso].qtd_avaliacoes > MAX_AVALIACOES) {
            printf("Quantidade de avaliações inválidas, insira uma quantidade válida.\n");
        }

    } while (turmas[opcao_acesso].qtd_avaliacoes < 1 || turmas[opcao_acesso].qtd_avaliacoes > MAX_AVALIACOES); //repete o menu se a quantidade for inválida

    do {
        for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) { //percorre as avaliações e coleta nome e valor
            printf("\nSoma das notas: %.2f", soma_avaliacoes);
            printf("\nDigite o nome da %dª avaliação: ", i+1);
            getchar();
            fgets(turmas[opcao_acesso].nome_notas[i], sizeof(turmas[opcao_acesso].nome_notas[i]), stdin);
            turmas[opcao_acesso].nome_notas[i][strcspn(turmas[opcao_acesso].nome_notas[i], "\n")] = '\0'; //remove a quebra de linha após o fgets 
            do {
                printf("Digite o valor de %s: ", turmas[opcao_acesso].nome_notas[i]);
                scanf("%f", &turmas[opcao_acesso].valor_notas[i]);

                if (turmas[opcao_acesso].valor_notas[i] <= 0.0 || turmas[opcao_acesso].valor_notas[i] > 10.0) {
                    printf("Valor da nota inválida, ela deve ser maior que 0 e menor que 10.\n");
                }

            } while (turmas[opcao_acesso].valor_notas[i] <= 0.0 || turmas[opcao_acesso].valor_notas[i] > 10.0);
            soma_avaliacoes += turmas[opcao_acesso].valor_notas[i]; //coleta e soma todas as notas
        }

        if (soma_avaliacoes != 10.0) {
            printf("\n - A soma das avaliações atingiu a pontuação de %.2f, preencha novamente com os valores corretos para atingir 10 pontos.\n", soma_avaliacoes);
            soma_avaliacoes = 0; //reseta a soma das avaliações se não atingir 10
        }
    } while (soma_avaliacoes != 10.0); //repete o menu se a soma for diferente dos 10 pontos

    do {
        printf("\nDigite a média da turma: ");
        scanf("%f", &turmas[opcao_acesso].media);
        if (turmas[opcao_acesso].media <= 0.0 || turmas[opcao_acesso].media >= 10) {
            printf("\nA média da turma deve ser maior que 0 e menor que 10.");
        }
    } while (turmas[opcao_acesso].media <= 0.0 || turmas[opcao_acesso].media >= 10);

    printf("\nAvaliações cadastradas com sucesso.\n");
    av_cadastrada[opcao_acesso] = true; //a turma selecionada recebe que as avaliações foram cadastradas
}

void editar_avaliacoes(int opcao_acesso, bool av_cadastrada[opcao_acesso]) {
    int opcao;

    if (av_cadastrada[opcao_acesso] == true) {
        do {
            printf("\n - Selecione o que deseja editar:\n");
            printf("[1] Nome da avaliação\n");
            printf("[2] Nota da avaliação\n");
            printf("[3] Média da turma\n");
            printf("[4] Voltar ao menu\n");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: 
                    editar_nome_avaliacao(opcao_acesso);
                    break;
                case 2:
                    editar_nota_avaliacao(opcao_acesso);
                    break;
                case 3:
                    do {
                        printf("\n - Digite a nova média da turma: ");
                        scanf("%f", &turmas[opcao_acesso].media);
                        if (turmas[opcao_acesso].media <= 0.0 || turmas[opcao_acesso].media >= 10.0) {
                            printf("\nA média da turma deve ser maior que 0 e menor que 10.\n");
                        } else {
                            printf("\nMédia editada com sucesso.\n");
                        }
                    } while (turmas[opcao_acesso].media <= 0.0 || turmas[opcao_acesso].media >= 10.0);
                    break;
                case 4:
                    break;
                default:
                    printf("\nSelecione uma opção existente.\n");
                }
        } while (opcao != 4);
    } else {
        printf("\nNão há avaliações para editar nessa turma.\n");
    }
}

void editar_nome_avaliacao (int opcao_acesso) {
    int opcao_edit;

    do {
        printf("\n - Digite o número da avaliação que deseja editar:\n");
        for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
            printf("[%d] %s\n", i, turmas[opcao_acesso].nome_notas[i]);
        }
        scanf("%d", &opcao_edit);
        if (opcao_edit >= 0 && opcao_edit < turmas[opcao_acesso].qtd_avaliacoes) {
            printf("\nDigite o novo nome da avaliação: ");
            getchar();
            fgets(turmas[opcao_acesso].nome_notas[opcao_edit], sizeof(turmas[opcao_acesso].nome_notas[opcao_edit]), stdin);
            turmas[opcao_acesso].nome_notas[opcao_edit][strcspn(turmas[opcao_acesso].nome_notas[opcao_edit], "\n")] = '\0'; //consome a quebra de linha
            printf("Nome da avaliação alterado.\n");
        } else {
            printf("\nNúmero inválido, selecione um número correto.\n");
        }
    } while (opcao_edit < 0 || opcao_edit >= turmas[opcao_acesso].qtd_avaliacoes); //repete o menu se o número da avaliação for inválido
}

void editar_nota_avaliacao (int opcao_acesso) {
    int opcao_edit;
    float soma_avaliacoes = 0.0, diferenca = 0.0;

    do {
        do {
            printf("\n - Digite o número da avaliação que deseja editar:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
                printf("[%d] %s - %.2f\n", i, turmas[opcao_acesso].nome_notas[i], turmas[opcao_acesso].valor_notas[i]);
                soma_avaliacoes += turmas[opcao_acesso].valor_notas[i];
            }
            scanf("%d", &opcao_edit);

            if (opcao_edit >= 0 && opcao_edit < turmas[opcao_acesso].qtd_avaliacoes) {
                diferenca = soma_avaliacoes - turmas[opcao_acesso].valor_notas[opcao_edit]; //é calculado a nova soma de notas, removendo aquela que o valor será alterado
                printf("\nSoma das notas: %.2f\n", diferenca);
                do {
                    printf("\nDigite a nova nota da avaliação: ");
                    scanf("%f", &turmas[opcao_acesso].valor_notas[opcao_edit]);

                    if (turmas[opcao_acesso].valor_notas[opcao_edit] <= 0.0 || turmas[opcao_acesso].valor_notas[opcao_edit] > 10.0) {
                        printf("Valor da nota inválida, ela deve ser maior que 0 e menor que 10.\n");
                    }

                } while (turmas[opcao_acesso].valor_notas[opcao_edit] <= 0.0 || turmas[opcao_acesso].valor_notas[opcao_edit] > 10.0);
                diferenca += turmas[opcao_acesso].valor_notas[opcao_edit]; //é calculada a nova soma das notas
            } else {
                printf("\nNúmero inválido, selecione um número correto.\n");
            }

            if (diferenca != 10.0) {
                printf("\n - A soma das avaliações atingiu a pontuação de %.2f, preencha novamente com os valores corretos para atingir 10 pontos.\n", diferenca);
                diferenca = 0; //reseta a soma das avaliações após edição se não atingir 10
                soma_avaliacoes = 0; //reseta a soma de todas as avaliações
            }

        } while (diferenca != 10.0); //repete se a soma das avaliações não for 10
    } while (opcao_edit < 0 || opcao_edit >= turmas[opcao_acesso].qtd_avaliacoes); //repete o menu se o número da avaliação for inválido
    printf("Nota da avaliação alterada.\n");
}

void listar_avaliacoes(int opcao_acesso, bool av_cadastrada[opcao_acesso]) {

    if (av_cadastrada[opcao_acesso]) { //só lista se naquela turma, a avaliação foi cadastrada
        printf("\n- Avaliações do %dº ano %c:\n", turmas[opcao_acesso].serie, turmas[opcao_acesso].turma);
        for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
            printf("Nome da avaliação nº %d: %s\n", i+1, turmas[opcao_acesso].nome_notas[i]);
            printf("> Valor: %.2f\n", turmas[opcao_acesso].valor_notas[i]);
        }
        printf("\nMédia: %.2f\n", turmas[opcao_acesso].media);
    } else {
        printf("\nNão há avaliações cadastradas para esta turma, cadastre.\n");
    }
}