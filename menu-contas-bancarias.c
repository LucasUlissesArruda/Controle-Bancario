<<<<<<< Updated upstream
=======
/*
Autor: Lucas Ulisses - Leonardo Henrique 
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
>>>>>>> Stashed changes
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"

// Declarar a lista global para acesso no menu
extern TipoLista lista;

void menucontasbancarias() {
    int opc;

    desenhar_tela();
    gotoxy(20, 10);
    printf("1- Cadastrar Contas Bancarias no Final");

    gotoxy(20, 11);
    printf("2- Cadastrar Contas Bancarias no Inicio");

    gotoxy(20, 12);
    printf("3- Cadastrar Contas Bancarias no Posicao");

    gotoxy(20, 13);
    printf("4- Remover Contas Bancarias no Final");

    gotoxy(20, 14);
    printf("5- Remover Contas Bancarias no Inicio");

    gotoxy(20, 15);
    printf("6- Remover Contas Bancarias no Posicao");

    gotoxy(20, 16);
    printf("7- Alteracao Contas Bancarias ");

    gotoxy(20, 17);
    printf("8- Consultar Contas Bancarias ");

    gotoxy(20, 18);
    printf("9- Retornar ao menu anterior ");

    gotoxy(2, 23);
    printf("Escolha uma opcao:");
    scanf("%d", &opc);

        if (opc == 1) {
        CadastrarContaFinal(&lista);
    }
    
        if (opc == 2) {
        CadastrarContaInicio(&lista);
    }

        if (opc == 4) {
        RemoverContaFinal(&lista);
    }
        if (opc == 5) {
        RemoverContaInicio(&lista);
    }
        if (opc == 8){
        consultarConta(&lista);
    }

        if (opc == 9) {
        telaprincipal();
    }
}