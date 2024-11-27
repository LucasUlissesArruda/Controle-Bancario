/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 21/11/2024
*/
#include <stdio.h>
#include "Funcoes.h"

// Função para listar todas as contas bancárias cadastradas
void consultaGeralContas(TipoLista *L) {
    system("cls"); 
    desenhar_tela();
    tipoApontador atual = L->Primeiro; 

    if (L->Primeiro == NULL) {
        gotoxy(7, 23);
        printf("Nenhuma conta cadastrada!\n");
        getch();
        menucontasbancarias();
        return;
    }

    gotoxy(7, 3);
    printf("LISTAGEM GERAL DE CONTAS BANCARIAS:\n");

    int contador = 1; // Contador para exibir a posição das contas

    // Exibe as contas uma por vez
    while (atual != NULL) {
        // Exibe os dados da conta
        gotoxy(7, 7);
        printf("Conta %d:", contador);

        gotoxy(7, 8);
        printf("Codigo: %d", atual->conteudo.codigo);

        gotoxy(7, 9);
        printf("Banco: %s", atual->conteudo.Banco);

        gotoxy(7, 10);
        printf("Agencia: %d", atual->conteudo.agencia);

        gotoxy(7, 11);
        printf("Numero da Conta: %d", atual->conteudo.numConta);

        gotoxy(7, 12);
        printf("Tipo da Conta: %s", atual->conteudo.tipo_conta);

        gotoxy(7, 13);
        printf("Saldo: %.2f", atual->conteudo.saldo);

        gotoxy(7, 14);
        printf("Limite: %.2f", atual->conteudo.Limite);

        gotoxy(7, 15);
        printf("Status da Conta: %d\n", atual->conteudo.statusConta);


        gotoxy(7, 23);
        printf("Pressione qualquer tecla para ver a próxima conta...");
        getch();
        

        system("cls");
        desenhar_tela();

        atual = atual->proximo; // Move para o próximo nó
        contador++;
    }
    getch();
    menucontasbancarias();
}