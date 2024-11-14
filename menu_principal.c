#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void desenhar_tela() {
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
    gotoxy(3, 3);
    printf("Calculo de Areas em C");
    gotoxy(66, 3);
    printf("Lucas");
}