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

    // ve se tem conta cadastrada
    if (L->Primeiro == NULL) {
        gotoxy(7, 23); 
        printf("Nenhuma Conta cadastrada!");
        getch();  
        menucontasbancarias(); 
        return;
    }

    // guarda a primeira conta
    temp = L->Primeiro;

    // mostra oq ela tem
    gotoxy(7, 5); 
    printf("Informacoes da primeira conta:");
    gotoxy(7, 7);
    printf("Codigo: %d", temp->conteudo.codigo);
    gotoxy(7, 8);
    printf("Banco: %s", temp->conteudo.Banco);    
    gotoxy(7, 9);
    printf("Agencia: %d", temp->conteudo.agencia); 
    gotoxy(7, 10);
    printf("Numero da Conta: %d", temp->conteudo.numConta); 
    gotoxy(7, 11);
    printf("Tipo de Conta: %s", temp->conteudo.tipo_conta); 
    gotoxy(7, 12);
    printf("Saldo: R$ %.2f", temp->conteudo.saldo);  
    gotoxy(7, 13);
    printf("Limite: R$ %.2f", temp->conteudo.Limite); 
    gotoxy(7, 14);
    printf("Status: %d", temp->conteudo.statusConta); 

    // tem crtz ?
    gotoxy(7, 16);
    printf("Deseja realmente remover esta conta? (1 - Sim / 2 - Não): ");
    scanf("%d", &confirmacao);

    // se nao for = 1 nao vai
    if (confirmacao != 1) {
        gotoxy(7, 18);
        printf("Operação cancelada.");
        getch();
        menucontasbancarias();
        return;
    }

    // guarda para remover
    temp = L->Primeiro;  

    if (L->Primeiro == L->Ultimo) {  
        // se for so um a lista zera
        L->Primeiro = NULL;
        L->Ultimo = NULL;
    } else {  
        // se nao vai para o proximo
        L->Primeiro = L->Primeiro->proximo;
    }

    free(temp);  // fumega ele
    gravar_contas(L); 
    gotoxy(7, 18); 
    printf("Conta removida com sucesso!"); 
    getch(); 
    MenuRemover(); 
}
