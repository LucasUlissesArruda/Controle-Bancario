#include "Funcoes.h"
#include <conio.h>

void RemoverContaFinal(TipoLista *L) {
    tipoApontador p, temp;
    int confirmacao;

    system("cls");
    desenhar_tela();

    if (L->Primeiro == NULL) {
        gotoxy(7, 12);
        printf("Nenhuma conta cadastrada!");
        getch();
        return;
    }

    temp = L->Ultimo;

    gotoxy(7, 7);
    printf("Ultima conta cadastrada:");
    gotoxy(7, 8);
    printf("Codigo: %d", temp->conteudo.codigo);
    gotoxy(7, 9);
    printf("Banco: %s", temp->conteudo.Banco);
    gotoxy(7, 10);
    printf("Agencia: %d", temp->conteudo.agencia);
    gotoxy(7, 11);
    printf("Numero da Conta: %d", temp->conteudo.numConta);
    gotoxy(7, 12);
    printf("Tipo de Conta: %s", temp->conteudo.tipo_conta);
    gotoxy(7, 13);
    printf("Saldo: R$ %.2f", temp->conteudo.saldo);
    gotoxy(7, 14);
    printf("Limite: R$ %.2f", temp->conteudo.Limite);
    gotoxy(7, 15);
    printf("Status: %d", temp->conteudo.statusConta);

    gotoxy(7, 17);
    printf("Deseja remover esta conta? (1 - Sim / 2 - Não): ");
    scanf("%d", &confirmacao);

    if (confirmacao != 1) {
        gotoxy(7, 19);
        printf("Operação cancelada.");
        getch();
        return;
    }

    if (L->Primeiro == L->Ultimo) {
        free(L->Primeiro);
        L->Primeiro = NULL;
        L->Ultimo = NULL;
    } else {
        p = L->Primeiro;
        while (p->proximo != L->Ultimo) {
            p = p->proximo;
        }
        free(L->Ultimo);
        L->Ultimo = p;
        L->Ultimo->proximo = NULL;
    }

    gotoxy(7, 19);
    printf("Conta removida com sucesso!");
     gravar_contas(L);
    getch();
    menucontasbancarias();
}
