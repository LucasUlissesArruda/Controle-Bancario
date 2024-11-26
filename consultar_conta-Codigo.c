#include <stdio.h>
#include "Funcoes.h"

// Função para consultar contas bancárias pelo número
void consultarContaCodigo(TipoLista *L) {
    system("cls");
    desenhar_tela();
    int opc;
    int numeroBusca;
    tipoApontador atual;
    int encontrado = 0;

    if (L->Primeiro == NULL) {
        gotoxy(7, 23);
        printf("Nenhuma conta cadastrada!\n");
        getch();
        menucontasbancarias();
        return;
    }
    
    gotoxy(7, 7);
    printf("Digite o Codigo da conta que deseja consultar: ");
    scanf("%d", &numeroBusca);

    atual = L->Primeiro;
    while (atual != NULL) {
        if (atual->conteudo.codigo == numeroBusca) {
            gotoxy(9, 7);
            printf("\nConta encontrada:\n");
            gotoxy(7, 10);
            printf("Codigo: %d\n", atual->conteudo.codigo);
            gotoxy(7, 11);
            printf("Banco: %s\n", atual->conteudo.Banco);
            gotoxy(7, 12);
            printf("Agencia: %d\n", atual->conteudo.agencia);
            gotoxy(7, 13);
            printf("Numero da Conta: %d\n", atual->conteudo.numConta);
            gotoxy(7, 14);
            printf("Tipo da Conta: %s\n", atual->conteudo.tipo_conta);
            gotoxy(7, 15);
            printf("Saldo: %.2f\n", atual->conteudo.saldo);
            gotoxy(7, 16);
            printf("Limite: %.2f\n", atual->conteudo.Limite);
            gotoxy(7, 17);
            printf("Status da Conta: %d\n", atual->conteudo.statusConta);
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (!encontrado) {
        gotoxy(7, 23);
        printf("\nConta com numero %d nao encontrada.\n", numeroBusca);
        getch();
        MenuConsultarContas(); 
    } else {
        gotoxy(7, 23);
        printf("Deseja fazer uma nova consulta? 1-Sim 2-Nao: ");
        scanf("%d", &opc);
        if (opc == 1) {
            consultarContaCodigo(L); 
        } else {
            MenuConsultarContas(); 
        }
    }
}
