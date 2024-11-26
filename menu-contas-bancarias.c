#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"

// Declarar a lista global para acesso no menu
extern TipoLista lista;

void menucontasbancarias() {
    int opc = 0;

    while (opc != 9) {
        system("cls");
        desenhar_tela();

        gotoxy(20, 10);
        printf("1- Cadastrar Contas Bancarias no Final");

        gotoxy(20, 11);
        printf("2- Cadastrar Contas Bancarias no Inicio");

        gotoxy(20, 12);
        printf("3- Cadastrar Contas Bancarias na Posicao");

        gotoxy(20, 13);
        printf("4- Remover Contas Bancarias no Final");

        gotoxy(20, 14);
        printf("5- Remover Contas Bancarias no Inicio");

        gotoxy(20, 15);
        printf("6- Remover Contas Bancarias na Posicao");

        gotoxy(20, 16);
        printf("7- Alteracao Contas Bancarias");

        gotoxy(20, 17);
        printf("8- Consultar Contas Bancarias");

        gotoxy(20, 18);
        printf("9- Retornar ao menu anterior");

        gotoxy(2, 23);
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        system("cls");

        if (opc == 1) {
            CadastrarContaFinal(&lista);
        } else if (opc == 2) {
            CadastrarContaInicio(&lista);
        } else if (opc == 3) {
            CadastrarContaPosicao(&lista);
        } else if (opc == 4) {
            RemoverContaFinal(&lista);
        } else if (opc == 5) {
            RemoverContaInicio(&lista);
        } else if (opc == 6) {
            RemoverContaPosicao(&lista);
        } else if (opc == 7) {
            AlterarConta(&lista); 
        } else if (opc == 8) {
            MenuConsultarContas(&lista);
        } else if (opc == 9) {
            telaprincipal();
        } else {
            gotoxy(7, 12);
            printf("Opcao invalida! Tente novamente.");
            getch();
        }
    }
}
