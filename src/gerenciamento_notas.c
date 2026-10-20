#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "gerenciamento_notas.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_avaliacoes.h"
#include "cadastro_turma.h"

Classificacao aluno_aux[MAX_ALUNOS]; //Struct auxiliar declarada no arquivo para ordenação

void lancar_notas (int opcao_acesso, bool av_cadastrada[MAX_TURMAS]) {
    int opcao_nota;

    if (av_cadastrada[opcao_acesso] == true && turmas[opcao_acesso].qtd_alunos > 0) { //Verifica se as avaliações naquela turma já foram cadastradas e se há  alunos naquela turma
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Digite o número do aluno que terá sua nota lançada:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
                printf("[%d] %s", i, turmas[opcao_acesso].alunos[i].nome);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao_nota);
            if (opcao_nota >= 0 && opcao_nota < turmas[opcao_acesso].qtd_alunos) {
                preencher_notas(opcao_acesso, opcao_nota);
            } else {
                printf("\nOpção inválida, selecione um aluno existente.");
            }
        } while (opcao_nota < 0 || opcao_nota >= turmas[opcao_acesso].qtd_alunos); 
    } else {
        printf("\nNão foi possível acessar o lançamento de notas, verifique se há alunos naquela turma e se você cadastrou avaliações.\n");
    } 
}

void preencher_notas(int opcao_acesso, int opcao_nota) {

    printf("\n- Insira as notas de %s", turmas[opcao_acesso].alunos[opcao_nota].nome);
    printf("Certifique-se que a nota esteja entre 0 e o valor da avaliação.\n");

    turmas[opcao_acesso].alunos[opcao_nota].boletim_disponivel = false;
    for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
        do {
            printf("\nInsira a nota de: %s [%.2f]: ", turmas[opcao_acesso].nome_notas[i], turmas[opcao_acesso].valor_notas[i]);
            scanf("%f", &turmas[opcao_acesso].alunos[opcao_nota].notas[i]);
            if (turmas[opcao_acesso].alunos[opcao_nota].notas[i] < 0 || turmas[opcao_acesso].alunos[opcao_nota].notas[i] > turmas[opcao_acesso].valor_notas[i]) {
                printf("\nA nota deve ser maior ou igual a 0 e menor ou igual ao valor da avaliação.\n");
            } else {
                printf("Nota lançada.\n");
            }
        } while (turmas[opcao_acesso].alunos[opcao_nota].notas[i] < 0 || 
        turmas[opcao_acesso].alunos[opcao_nota].notas[i] > turmas[opcao_acesso].valor_notas[i]); //Repete o menu se a nota for inválida (< 0 ou > do que o valor daquela avaliação)
    }
    turmas[opcao_acesso].alunos[opcao_nota].boletim_disponivel = true;
    printf("\n> Notas lançadas, confira o boletim do aluno e lance novamente as notas se quiser editar alguma nota.\n");
}

void ver_boletim (int opcao_acesso) {
    int opcao;
    float media = 0;
    if (turmas[opcao_acesso].qtd_alunos > 0) {

        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Digite o número do aluno que deseja ver o boletim:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
                printf("[%d] %s", i, turmas[opcao_acesso].alunos[i].nome);
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao);

            if (opcao >= 0 && opcao < turmas[opcao_acesso].qtd_alunos) {

                if (turmas[opcao_acesso].alunos[opcao].boletim_disponivel == true && av_cadastrada[opcao_acesso] == true) { 
                    //Verifica se o boletim já está disponível e se a turma teve avaliações cadastradas
                    media = 0;
                    printf("\n┌─────────────────────────────────────┐\n");
                    printf("- Boletim de %s\n", turmas[opcao_acesso].alunos[opcao].nome);
                    for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
                        printf("%s - Nota: %.2f/%.2f\n", turmas[opcao_acesso].nome_notas[i], turmas[opcao_acesso].alunos[opcao].notas[i], turmas[opcao_acesso].valor_notas[i]);
                        media += turmas[opcao_acesso].alunos[opcao].notas[i]; //Acumula a soma do aluno
                    }
                    printf("\nMédia: %.2f\n", media);

                    if (media >= turmas[opcao_acesso].media) {
                        printf("Status: aprovado\n"); 
                    } else {
                        printf("Status: reprovado\n");
                    }
                    printf("└─────────────────────────────────────┘\n");

                } else {
                    printf("\nNão foi possível consultar o boletim, verifique se o aluno teve suas notas lançadas e se a turma teve suas avaliações cadastradas.\n");
                }

            } else {
                printf("\nOpção inválida, selecione um aluno existente.");
            }
        } while (opcao < 0 || opcao >= turmas[opcao_acesso].qtd_alunos);

    } else {
        printf("\nNão há alunos cadastrados nessa turma.\n");
    }
}

void ver_estatisticas (int opcao_acesso) {
    int opcao;
    bool existe_um_boletim = false, crescente = false; //Crescente indica a variável booleana que serve como parametro para decidir qual ordenação será chamada

    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
        if (turmas[opcao_acesso].alunos[i].boletim_disponivel == true) { //Verifica se existe pelo menos um boletim disponivel ∃x(B(x) ^ D(x))
            existe_um_boletim = true;
            break;
        }
    }

    if (turmas[opcao_acesso].qtd_alunos > 0) {
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Selecione qual estatística deseja ver:\n");
            printf("\n[1] Ver médias em ordem crescente\n");
            printf("[2] Ver médias em ordem descrescente\n");
            printf("[3] Ver maior e menor nota de cada avaliação\n");
            printf("[4] Visualizar aprovados e reprovados\n");
            printf("[5] Voltar ao menu\n");
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao);
            if (opcao == 5) {
                break;
            }

            if (av_cadastrada[opcao_acesso] == true && existe_um_boletim == true) {
                switch (opcao) {
                    case 1:
                        crescente = true; //A função antes de ser acessada, recebe o true na variável "crescente", indicando que o algoritmo na função será o de ordem crescente
                        crescente_decrescente(opcao_acesso, crescente);
                        break;
                    case 2:
                        crescente = false; //A função crescente recebe false, indicando que o algoritmo de ordenação será o decrescente
                        crescente_decrescente(opcao_acesso, crescente);
                        break;
                    case 3:
                        maior_menor_nota_av(opcao_acesso);
                        break;
                    case 4:
                        aprovados_reprovados(opcao_acesso);
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpção inválida, selecione uma opção existente.\n");
                }
            } else {
                printf("\nNão foi possível acessar, verifique se algum aluno tem nota lançada e se a turma possui avaliações cadastradas.\n");
            }
        } while (opcao != 5);

    } else {
        printf("\nNão há alunos cadastrados nessa turma.\n");
    }
} 

void crescente_decrescente (int opcao_acesso, bool crescente) {
    int qtd_boletins_disponiveis = 0, k = 0; 
    //k = representa o indice do aluno que tem boletim disponível, fazendo com que o aluno com boletim disponivel,
    //tenha seus dados registrados de 1 em 1, ao inves de registrar apenas no índice de i quando a condição é cumprida

    Classificacao aux; //Auxiliar para ser o intermédio da struct

    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
        if (turmas[opcao_acesso].alunos[i].boletim_disponivel == true) {
            aluno_aux[k].media_final = 0; //Inicializa a média daquele aluno
            qtd_boletins_disponiveis++;
            strcpy(aluno_aux[k].nome, turmas[opcao_acesso].alunos[i].nome); //Copia o nome do aluno atual para a struct auxiliar
            for (int j = 0; j < turmas[opcao_acesso].qtd_avaliacoes; j++) {
                aluno_aux[k].media_final += turmas[opcao_acesso].alunos[i].notas[j]; //Copia todas as notas do aluno para a média dele
            }
            k++;
        }
    }
    
    //ALGORITMO DE ORDENAÇÃO CRESCENTE
    if (crescente == true) {
        for (int i = 0; i < qtd_boletins_disponiveis; i++) {
            for (int j = i+1; j < qtd_boletins_disponiveis; j++) {
                if (aluno_aux[i].media_final > aluno_aux[j].media_final) {
                    aux = aluno_aux[j];
                    aluno_aux[j] = aluno_aux[i];
                    aluno_aux[i] = aux;
                }
            }
        }
        printf("\n- Média dos alunos em ordem crescente:\n");
        for (int i = 0; i < qtd_boletins_disponiveis; i++) {
            printf("%.2f - %s", aluno_aux[i].media_final, aluno_aux[i].nome);
        }
    }

    //ALGORITMO DE ORDENAÇÃO DECRESCENTE
    if (!crescente) {
        for (int i = 0; i < qtd_boletins_disponiveis; i++) {
            for (int j = i+1; j < qtd_boletins_disponiveis; j++) {
                if (aluno_aux[i].media_final < aluno_aux[j].media_final) {
                    aux = aluno_aux[j];
                    aluno_aux[j] = aluno_aux[i];
                    aluno_aux[i] = aux;
                }
            }
        }
        printf("\n- Média dos alunos em ordem decrescente:\n");
        for (int i = 0; i < qtd_boletins_disponiveis; i++) {
            printf("%.2f - %s", aluno_aux[i].media_final, aluno_aux[i].nome);
        }
    }
}

void maior_menor_nota_av (int opcao_acesso) {
    float maior_nota = 0, menor_nota = 0;
    int u, l; //Constantes para guardar o índice das maiores e menores notas
    int qtd_boletins_disponiveis;

    for (int i = 0; i < turmas[opcao_acesso].qtd_avaliacoes; i++) {
        printf("%s:\n", turmas[opcao_acesso].nome_notas[i]); //Diz qual avaliação está sendo analisada

        for (int q = 0; q < turmas[opcao_acesso].qtd_alunos; q++) {
            if (turmas[opcao_acesso].alunos[q].boletim_disponivel == true) { //Procura o primeiro aluno com boletim disponnível para assumir a maior e menor nota
                maior_nota = turmas[opcao_acesso].alunos[q].notas[i];
                menor_nota = turmas[opcao_acesso].alunos[q].notas[i];
                u = q;
                l = q;
                break;
            }
        }
        qtd_boletins_disponiveis = 0;

        for (int j = 0; j < turmas[opcao_acesso].qtd_alunos; j++) {
            if (!turmas[opcao_acesso].alunos[j].boletim_disponivel) { //Pula alunos sem boletim
                continue;
            } else {
                qtd_boletins_disponiveis++;
            }
            if (turmas[opcao_acesso].alunos[j].notas[i] > maior_nota) {
                maior_nota = turmas[opcao_acesso].alunos[j].notas[i];
                u = j;
            } 
            if (turmas[opcao_acesso].alunos[j].notas[i] < menor_nota) {
                menor_nota = turmas[opcao_acesso].alunos[j].notas[i];
                l = j;
            }
        }
        printf("Maior nota: %.2f - %s", maior_nota, turmas[opcao_acesso].alunos[u].nome);
        printf("Menor nota: %.2f - %s\n", menor_nota, turmas[opcao_acesso].alunos[l].nome);
    }

    if (qtd_boletins_disponiveis == 1) { //Verifica se há só um aluno com boletim disponível, se sim, ele exibe a mensagem abaixo
        printf("> Estatísticas baseadas no único aluno com boletim disponível.\n");
    }
}

void aprovados_reprovados (int opcao_acesso) {
    float media;
    bool existe_reprovado = false;
    bool existe_aprovado = false;

    printf("\n> Alunos aprovados:\n");
    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { //Percorre todos os alunos
        media = 0;
        if (!turmas[opcao_acesso].alunos[i].boletim_disponivel) { //Pula alunos sem boletim
            continue;
        }
        for (int j = 0; j < turmas[opcao_acesso].qtd_avaliacoes; j++) { //Percorre todas as avaliações
            media += turmas[opcao_acesso].alunos[i].notas[j]; //Calcula a média de cada aluno    
        }
        if (media >= turmas[opcao_acesso].media) {
            printf("\nMédia: %.2f - %s", media, turmas[opcao_acesso].alunos[i].nome);
            existe_aprovado = true;
        }
    } 

    if (!existe_aprovado) {
        printf("\nNão há aprovados na turma.\n");
    }
    
    printf("\n> Alunos reprovados:\n");
    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { 
        media = 0;
        if (!turmas[opcao_acesso].alunos[i].boletim_disponivel) { 
            continue;
        }
        for (int j = 0; j < turmas[opcao_acesso].qtd_avaliacoes; j++) { 
            media += turmas[opcao_acesso].alunos[i].notas[j];     
        }
        if (media < turmas[opcao_acesso].media) {
            printf("\nMédia: %.2f - %s", media, turmas[opcao_acesso].alunos[i].nome);
            existe_reprovado = true;
        }
    }

    if (!existe_reprovado) {
        printf("\nNão há reprovados na turma.\n");
    }
}