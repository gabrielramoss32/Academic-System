#include<stdio.h>
#include<windows.h>
#include "menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída em todo o projeto
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada
    menu_inicial(); //Inicializa o codigo e chama a função localizada em menu.c do header menu.h, tudo começa aqui
    return 0;
}
