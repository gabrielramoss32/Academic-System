#ifndef GERENCIAMENTO_TURMA_H
#define GERENCIAMENTO_TURMA_H

typedef struct {
    int serieEdit;
    char turmaEdit;
    char turnoEdit[15];
    char disciplinaEdit[40];
} TurmaEdit;

extern TurmaEdit turma_editada; //variavel da struct de turma editada, declarada em gerenciamento_turma.c

void acessar_turma ();
void editar_turma ();

#endif