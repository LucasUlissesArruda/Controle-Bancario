#include "Funcoes.h"
#include <conio.h>

void RemoverContaPosicao(TipoLista *L) {
    tipoApontador atual, anterior;
    int posicao, contador = 1, confirmacao;

    system("cls");
    desenhar_tela();

    if (L->Primeiro == NULL) {
        gotoxy(7, 12);
        printf("Nenhuma conta cadastrada!");
        getch();
        return;
    }

    gotoxy(7, 7);
    printf("Digite a posicao da conta a ser removida: ");
    scanf("%d", &posicao);

    atual = L->Primeiro;
    anterior = NULL;

    while (atual != NULL && contador < posicao) {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL || posicao < 1) {
        gotoxy(7, 9);
        printf("Posição invalida!");
        getch();
        return;
    }

    gotoxy(7, 9);
    printf("Conta encontrada:");
    gotoxy(7, 10);
    printf("Codigo: %d", atual->conteudo.codigo);
    gotoxy(7, 11);
    printf("Banco: %s", atual->conteudo.Banco);
    gotoxy(7, 12);
    printf("Agencia: %d", atual->conteudo.agencia);
    gotoxy(7, 13);
    printf("Numero da Conta: %d", atual->conteudo.numConta);
    gotoxy(7, 14);
    printf("Tipo de Conta: %s", atual->conteudo.tipo_conta);
    gotoxy(7, 15);
    printf("Saldo: R$ %.2f", atual->conteudo.saldo);
    gotoxy(7, 16);
    printf("Limite: R$ %.2f", atual->conteudo.Limite);
    gotoxy(7, 17);
    printf("Status: %d", atual->conteudo.statusConta);

    gotoxy(7, 19);
    printf("Deseja realmente remover esta conta? (1 - Sim / 2 - Não): ");
    scanf("%d", &confirmacao);

    if (confirmacao != 1) {
        gotoxy(7, 21);
        printf("Operacao cancelada.");
        getch();
        return;
    }

    if (atual == L->Primeiro) { 
        L->Primeiro = atual->proximo;
        if (atual == L->Ultimo) {
            L->Ultimo = NULL;
        }
    } else { 
        anterior->proximo = atual->proximo;
        if (atual == L->Ultimo) {
            L->Ultimo = anterior;
        }
    }

    free(atual);
     gravar_contas(L);

    gotoxy(7, 21);
    printf("Conta removida com sucesso!");
    getch();
    menucontasbancarias();
}
