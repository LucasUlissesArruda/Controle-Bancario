/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/

#include "Funcoes.h"
#include <conio.h>

void RemoverContaInicio(TipoLista *L) {
    system("cls");
    desenhar_tela();
    tipoApontador temp;
    int confirmacao;

    if (L->Primeiro == NULL) {
        gotoxy(7, 23);
        printf("Nenhuma Conta cadastrada!\n");
        getch();
        menucontasbancarias();
        return;
    }

    // Exibir informações da primeira conta
    temp = L->Primeiro;
    gotoxy(7, 5);
    printf("Informações da primeira conta:\n");
    gotoxy(7, 7);
    printf("Código: %d", temp->conteudo.codigo);
    gotoxy(7, 8);
    printf("Banco: %s", temp->conteudo.Banco);
    gotoxy(7, 9);
    printf("Agência: %d", temp->conteudo.agencia);
    gotoxy(7, 10);
    printf("Número da Conta: %d", temp->conteudo.numConta);
    gotoxy(7, 11);
    printf("Tipo de Conta: %s", temp->conteudo.tipo_conta);
    gotoxy(7, 12);
    printf("Saldo: R$ %.2f", temp->conteudo.saldo);
    gotoxy(7, 13);
    printf("Limite: R$ %.2f", temp->conteudo.Limite);
    gotoxy(7, 14);
    printf("Status: %d", temp->conteudo.statusConta);

    gotoxy(7, 16);
    printf("Deseja realmente remover esta conta? (1 - Sim / 2 - Não): ");
    scanf("%d", &confirmacao);

    if (confirmacao != 1) {
        gotoxy(7, 18);
        printf("Operação cancelada.\n");
        getch();
        return;
    }

    // Remoção da conta
    temp = L->Primeiro;
    if (L->Primeiro == L->Ultimo) { 
        L->Primeiro = NULL;
        L->Ultimo = NULL;
    } else {  
        L->Primeiro = L->Primeiro->proximo;
    }

    free(temp);
    gravar_contas(L);

    gotoxy(7, 18);
    printf("Conta removida com sucesso!\n");
    gravar_contas(L);
    getch();
    menucontasbancarias();
}
