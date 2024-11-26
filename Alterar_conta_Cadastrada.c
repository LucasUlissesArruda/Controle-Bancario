#include "Funcoes.h"
#include <conio.h>

void AlterarConta(TipoLista *L) {
    tipoApontador atual;
    int codigo, encontrou = 0;

    system("cls");
    desenhar_tela();

    if (L->Primeiro == NULL) {
        gotoxy(7, 12);
        printf("Nenhuma conta cadastrada!");
        getch();
        return; 
    }

    gotoxy(7, 7);
    printf("Digite o codigo da conta a ser alterada: ");
    scanf("%d", &codigo);

    atual = L->Primeiro;

    while (atual != NULL) {
        if (atual->conteudo.codigo == codigo) {
            encontrou = 1;
            system("cls");
            desenhar_tela();

            gotoxy(7, 7);
            printf("Conta encontrada:");
            gotoxy(7, 8);
            printf("Codigo: %d", atual->conteudo.codigo);
            gotoxy(7, 9);
            printf("Banco: %s", atual->conteudo.Banco);
            gotoxy(7, 10);
            printf("Agencia: %d", atual->conteudo.agencia);
            gotoxy(7, 11);
            printf("Numero da Conta: %d", atual->conteudo.numConta);
            gotoxy(7, 12);
            printf("Tipo de Conta: %s", atual->conteudo.tipo_conta);
            gotoxy(7, 13);
            printf("Saldo: R$ %.2f", atual->conteudo.saldo);
            gotoxy(7, 14);
            printf("Limite: R$ %.2f", atual->conteudo.Limite);
            gotoxy(7, 15);
            printf("Status: %d", atual->conteudo.statusConta);

            gotoxy(7, 17);
            printf("Digite os novos dados da conta:");
            gotoxy(7, 18);
            printf("Banco: ");
            fflush(stdin);
            fgets(atual->conteudo.Banco, 50, stdin);
           

            gotoxy(7, 19);
            printf("Agencia: ");
            scanf("%d", &atual->conteudo.agencia);

            gotoxy(7, 20);
            printf("Numero da Conta: ");
            scanf("%d", &atual->conteudo.numConta);

            gotoxy(7, 21);
            printf("Tipo de Conta: ");
            fflush(stdin);
            fgets(atual->conteudo.tipo_conta, 50, stdin);
            
            gotoxy(7, 22);
            printf("Saldo: ");
            scanf("%f", &atual->conteudo.saldo);

            gotoxy(7, 23);
            printf("Limite: ");
            scanf("%f", &atual->conteudo.Limite);

            gotoxy(7, 24);
            printf("Status (0 - Inativa, 1 - Ativa): ");
            scanf("%d", &atual->conteudo.statusConta);

            gotoxy(7, 26);
            printf("Conta alterada com sucesso!");
            getch();

            menucontasbancarias(); 
            return;
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        gotoxy(7, 9);
        printf("Conta nao encontrada!");
        getch();
    }

    menucontasbancarias(); 
}
