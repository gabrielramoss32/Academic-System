#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include "cadastro_turma.h"
#include "gerenciamento_aluno.h"
#include "gerenciamento_turma.h"

bool função_primaria; //variável para controlar o acesso a função de verificação de matrícula

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
        printf("[6] Buscar aluno\n"); //pronto
        printf("[7] Ver estatísticas da turma\n");
        printf("[8] Excluir aluno\n"); //pronto
        printf("[9] Voltar ao menu\n"); //pronto
        printf("└─────────────────────────────────────┘\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (turmas[opcao_acesso].qtd_alunos >= MAX_ALUNOS) { //verifica se a turma já está cheia
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
                buscar_aluno(opcao_acesso);
                break;
            case 7:

                break; 
            case 8:
                excluir_aluno(opcao_acesso);
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

    printf("Insira o nome do aluno (priorize colocar nomes sem acento, pois a busca ignora acentos): ");
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
                        if (i == opcao_edit) { //evita de comparar a matricula com ela mesma e pula o laço
                            continue;
                        }
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

void excluir_aluno (int opcao_acesso) {

    int opcao; //variável para decidir qual aluno será excluido
    char confirm; //variável de confirmação da exclusão

    if (turmas[opcao_acesso].qtd_alunos > 0) { //verifica se tem alunos para excluir
        do {
            printf("\n┌─────────────────────────────────────┐\n");
            printf("- Digite o número do aluno que deseja excluir:\n");
            for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
                printf("[%d] %s", i, turmas[opcao_acesso].alunos[i].nome); //lista todos os alunos disponíveis para exclusão
            }
            printf("└─────────────────────────────────────┘\n");
            scanf("%d", &opcao);

            if (opcao >= 0 && opcao < turmas[opcao_acesso].qtd_alunos) { //verifica se é um aluno válido
                printf("\nDeseja realmente excluir esse aluno? (S/N)\n");
                printf("Quantidade de alunos: %d >>> %d\n", turmas[opcao_acesso].qtd_alunos, turmas[opcao_acesso].qtd_alunos - 1);
                scanf(" %c", &confirm);
                if (confirm == 'S' || confirm == 's') {
                    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos - opcao - 1; i++) {
                        turmas[opcao_acesso].alunos[opcao] = turmas[opcao_acesso].alunos[opcao + 1];
                        opcao++; //incrementa para deslocar os próximos alunos
                    }
                    turmas[opcao_acesso].qtd_alunos--; //retira uma quantidade de alunos cadastrados
                    opcao = 0; //zera a variável da opção
                    printf("\nExclusão bem sucedida, você retornará ao menu.\n");
                } else {
                    printf("\nExclusão cancelada, você retornará ao menu.\n");
                }
            } else {
                printf("\nOpção inválida, selecione um aluno existente.\n");
            }
        } while (opcao < 0 || opcao > turmas[opcao_acesso].qtd_alunos);
    } else {
        printf("\nNão há aluno para ser excluído, cadastre um aluno.\n");
    }
}

void buscar_aluno(int opcao_acesso) {
    int opcao; //variável para decidir de qual forma o aluno será procurado
    
    printf("\n- Selecione como deseja procurar o aluno: \n");
    printf("[1] Por matrícula\n");
    printf("[2] Por nome\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            busca_por_matricula(opcao_acesso);
            break;
        case 2:
            busca_por_nome(opcao_acesso);
            break;
    }
}

void busca_por_matricula(int opcao_acesso) {
    int matricula_buscada; //representa a matrícula procurada
    bool encontrado = false; //variável para controlar a busca do aluno pela matrícula

    printf("\nDigite a matrícula do aluno que deseja procurar: ");
    scanf("%d", &matricula_buscada);
    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) {
        if (matricula_buscada == turmas[opcao_acesso].alunos[i].matricula) { //compara a matrícula buscada com todas as matrículas registradas
            printf("\nAluno encontrado. \n");
            printf("Nome: %s", turmas[opcao_acesso].alunos[i].nome);
            printf("Matrícula: %d\n", turmas[opcao_acesso].alunos[i].matricula);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("\nAluno não encontrado.\n");
    }
}

void busca_por_nome (int opcao_acesso) {
    char nome_buscado[100]; //representa o aluno que a pessoa quer buscar
    char nome_temporario[100]; //representa a cópia temporária que será usada para comparação
    bool encontrado = false; //variável booleana para controlar se a busca do aluno foi bem sucedida

    printf("\nDigite o nome do aluno que deseja procurar: ");
    getchar();
    fgets(nome_buscado, sizeof(nome_buscado), stdin);
    for (int i = 0; i < strlen(nome_buscado); i++) {
        nome_buscado[i] = tolower(nome_buscado[i]); //normaliza o nome buscado para ficar todo em minúsculo
    }

    for (int i = 0; i < turmas[opcao_acesso].qtd_alunos; i++) { //percorre todos os alunos
        strcpy(nome_temporario, turmas[opcao_acesso].alunos[i].nome); //copia o nome do aluno atual para o nome temporário
        for (int j = 0; j < strlen(turmas[opcao_acesso].alunos[i].nome); j++) { //percorre cada caractere do nome do aluno
            nome_temporario[j] = tolower(nome_temporario[j]); //normaliza o nome buscado para ficar todo em minúsculo
        }
        
        if (strstr(nome_temporario, nome_buscado) != NULL) { //compara o nome inserido e verifica se há um nome igual
            printf("\nAluno encontrado.\n");
            printf("Nome: %s", turmas[opcao_acesso].alunos[i].nome);
            printf("Matrícula: %d\n", turmas[opcao_acesso].alunos[i].matricula);
            encontrado = true;
        }
    }

    if (!encontrado) { //verifica se algum aluno com o nome buscado não foi encontrado
        printf("\nAluno não encontrado.\n");
    }
}