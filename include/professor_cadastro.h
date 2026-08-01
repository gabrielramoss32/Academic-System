#ifndef PROFESSOR_CADASTRO_H
#define PROFESSOR_CADASTRO_H
#include<stdbool.h>

typedef struct {
    int id;
    int idade;
    char nome[100];
    char formacao[50];
    char escola[100];
    bool cadastrado;
} Professor; //struct com as informações do professor

void cadastro_professor ();

#endif