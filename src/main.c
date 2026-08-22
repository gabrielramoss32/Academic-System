#include<stdio.h>
#include<windows.h>
#include "menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); //Configura para permitir acentos na saída
    SetConsoleCP(CP_UTF8); //Configura para permitir acentos na entrada
    menu_inicial(); //Inicializa o codigo e chama a função localizada em menu.c do header menu.h
    return 0;
}
