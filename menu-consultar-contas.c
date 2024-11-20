/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"

// Declarar a lista global para acesso no menu
extern TipoLista lista;

void MenuConsultarContas() {
    int opc;

    desenhar_tela();
    gotoxy(20, 10);
    printf("1 - Consulta Geral Contas Bancarias");

    gotoxy(20, 12);
    printf("2 - Consulta por Codigo Conta Bancarias");

    gotoxy(20, 14);
    printf("3 - Consulta Ordem Codigo Contas Bancarias");

    gotoxy(20, 16);
    printf("4 - Consultar Ordem Alfabetica Contas Bancarias");

    gotoxy(20, 18);
    printf("5 - Retornar ao menu anterior ");

    gotoxy(2, 23);
    printf("Escolha uma opcao:");
    scanf("%d", &opc);

        if (opc == 1) {
        
    }
    
        if (opc == 2) {
        consultarConta(&lista);
    }

        if (opc == 3) {
        RemoverContaFinal(&lista);
    }
        if (opc == 4) {
        RemoverContaInicio(&lista);
    }if (opc == 5) {
        menucontasbancarias();
    }
}