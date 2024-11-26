#include <stdio.h>
#include "Funcoes.h"


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

    int contador = 1; 

    
    while (atual != NULL) {
       
        gotoxy(7, 5);
        printf("Conta %d:", contador);

        gotoxy(7, 6);
        printf("Codigo: %d", atual->conteudo.codigo);

        gotoxy(7, 7);
        printf("Banco: %s", atual->conteudo.Banco);

        gotoxy(7, 8);
        printf("Agencia: %d", atual->conteudo.agencia);

        gotoxy(7, 9);
        printf("Numero da Conta: %d", atual->conteudo.numConta);

        gotoxy(7, 10);
        printf("Tipo da Conta: %s", atual->conteudo.tipo_conta);

        gotoxy(7, 11);
        printf("Saldo: %.2f", atual->conteudo.saldo);

        gotoxy(7, 12);
        printf("Limite: %.2f", atual->conteudo.Limite);

        gotoxy(7, 13);
        printf("Status da Conta: %s\n", (atual->conteudo.statusConta == 1 ? "Ativa" : "Inativa"));

        gotoxy(7, 15);
        printf("Pressione qualquer tecla para ver a proxima conta...");
        getch(); 
        
        system("cls");
        desenhar_tela(); 

        atual = atual->proximo; 
        contador++;
    }


    getch();
    menucontasbancarias();
}
