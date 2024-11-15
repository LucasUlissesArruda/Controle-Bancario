/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menumovibancarias(){
    int opc;
    desenhar_tela();

    gotoxy (20,10);
    printf("1- Movimentacao de Debito e Credito");

    gotoxy(20,12);
    printf("2- Transferencia entre Contas Bancarias");

    gotoxy(20,14);
    printf("3- Consulta Movimentacoes Bancarias");

    gotoxy(20,16);
    printf("4- Retornar ao Menu Anterior");

    gotoxy(2, 23);
    printf("Escolha uma opcao:");
    scanf("%d", &opc);

    if(opc == 4){
        telaprincipal();
    }
}