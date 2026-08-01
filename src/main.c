#include<stdio.h>
#include "menu.h"
#include "professor_cadastro.h"

Professor professor = {
    .cadastrado = false //professor global definido como sem cadastro
};

int main() {
    menu_inicial(); //Inicializa o codigo e chama a função localizada em menu.c do header menu.h
    return 0;
}
