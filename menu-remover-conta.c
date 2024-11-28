#include "funcoes.h"
void desenhar_remover() {
    system("cls");
    mudar_cor(0x5);
    int lin;

    for (lin = 1; lin < 25; lin++) {
        gotoxy(1, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }

    gotoxy(1, 1);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 4);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(1, 24);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(3, 2);
    printf("UNICV");
    gotoxy(60, 2);
    printf("Estrutura de dados");
    gotoxy(25, 2);
    printf("Sistema de Controle Bancario");
    gotoxy(30,3);
    printf("Menu Remoção");
    gotoxy(60, 3);
    printf("Lucas e Leonardo");
}