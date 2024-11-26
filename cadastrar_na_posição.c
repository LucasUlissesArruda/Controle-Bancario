#include "Funcoes.h"
#include <conio.h>

void CadastrarContaPosicao(TipoLista *L, int posicao) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador p, atual, anterior;
    int contador = 1;

    
    gotoxy(7, 7);
    printf("Codigo: ");
    scanf("%d", &conta.codigo);

    gotoxy(7, 8);
    printf("Nome do banco: ");
    fflush(stdin);
    fgets(conta.Banco, 50, stdin);
    

    gotoxy(7, 9);
    printf("Digite a agencia: ");
    scanf("%d", &conta.agencia);

    gotoxy(7, 10);
    printf("Digite o numero da conta: ");
    scanf("%d", &conta.numConta);

    gotoxy(7, 11);
    printf("Digite o tipo de conta: ");
    fflush(stdin);
    fgets(conta.tipo_conta, 50, stdin);
    

    gotoxy(7, 12);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    gotoxy(7, 13);
    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

    gotoxy(2, 23);
    printf("Digite o status da conta (0 - Inativa, 1 - Ativa): ");
    scanf("%d", &conta.statusConta);

    
    p = (tipoApontador)malloc(sizeof(TipoItem));
    if (p == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }

    
            p->conteudo = conta;
            p->proximo = NULL;

    
    if (posicao == 1 || L->Primeiro == NULL) {
        p->proximo = L->Primeiro;
        L->Primeiro = p;

        if (L->Ultimo == NULL) {  
            L->Ultimo = p;
        }

        printf("Conta cadastrada na posicao %d (inicio) com sucesso!\n", posicao);
        return;
    }

    
    atual = L->Primeiro;
    anterior = NULL;

    while (atual != NULL && contador < posicao) {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    if (contador < posicao) {
        printf("Posicao invalida! A lista tem menos elementos do que a posicao solicitada.\n");
        free(p); 
        return;
    }

    
    anterior->proximo = p;
    p->proximo = atual;

    
    if (atual == NULL) {
        L->Ultimo = p;
    }

    printf("Conta cadastrada na posicao %d com sucesso!\n", posicao);

    menucontasbancarias();
}
