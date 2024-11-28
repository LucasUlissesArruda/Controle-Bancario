#include "funcoes.h"

void MenuRemover() {
    int opc;

    desenhar_tela();
    gotoxy(20, 10);
    printf("1 - Remover no Inicio");

    gotoxy(20, 12);
    printf("2 - Remover no Final");

    gotoxy(20, 14);
    printf("3 - Remover na Posicao");

    gotoxy(20, 16);
    printf("4 - Retornar ao menu anterior");

    gotoxy(2, 23);
    printf("Escolha uma opcao:");
    scanf("%d", &opc);

        if (opc == 1) {
        RemoverContaInicio(&lista);
    }
    
        if (opc == 2) {
        RemoverContaFinal(&lista);
    }

        if (opc == 3) {
        RemoverContaPosicao(&lista);
    }
        if (opc == 4) {
        menucontasbancarias();
    }
}