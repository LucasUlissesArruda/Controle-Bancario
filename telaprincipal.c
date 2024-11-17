/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void telaprincipal() {
    desenhar_tela();
    int opc;
    gotoxy(20, 9);
    printf("1- Contas Bancarias");

    gotoxy(20, 12);
    printf("2 - Movimentacao Bancaria");

    gotoxy(20, 15);
    printf("3 - Sair do Programa");

    gotoxy(2, 23);
    printf("Escolha uma opcao:");
    scanf("%d", &opc);

    if (opc == 1){
        menucontasbancarias();
    }
    else if(opc == 2){
        menumovibancarias();
    }
    else if(opc == 3){
        exit;
    }
}
