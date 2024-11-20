#include <stdio.h>
#include "Funcoes.h"

// Função para listar todas as contas bancárias cadastradas
void consultaGeralContas(TipoLista *L) {
    system("cls"); // Limpa a tela para a exibição
    desenhar_tela(); // Desenha o layout padrão da tela
    tipoApontador_conta atual = L->Primeiro; // Ponteiro para percorrer a lista

    if (L->Primeiro == NULL) {
        gotoxy(7, 23);
        printf("Nenhuma conta cadastrada!\n");
        getch();
        menucontasbancarias(); // Volta para o menu se a lista estiver vazia
        return;
    }

    gotoxy(7, 3);
    printf("LISTAGEM GERAL DE CONTAS BANCARIAS:\n");

    // Exibe as contas uma por vez, esperando a interação do usuário
    while (atual != NULL) {
        // Exibe os dados da conta
        gotoxy(7, 5);
        printf("Codigo: %d", atual->conteudo.codigo);

        gotoxy(7, 6);
        printf("Banco: %s", atual->conteudo.Banco);

        gotoxy(7, 7);
        printf("Agencia: %d", atual->conteudo.agencia);

        gotoxy(7, 8);
        printf("Numero da Conta: %d", atual->conteudo.numConta);

        gotoxy(7, 9);
        printf("Tipo da Conta: %s", atual->conteudo.tipo_conta);

        gotoxy(7, 10);
        printf("Saldo: %.2f", atual->conteudo.saldo);

        gotoxy(7, 11);
        printf("Limite: %.2f", atual->conteudo.Limite);

        gotoxy(7, 12);
        printf("Status da Conta: %d\n", atual->conteudo.statusConta);

        // Aguardar o usuário pressionar uma tecla para ver a próxima conta
        gotoxy(7, 14);
        printf("Pressione qualquer tecla para ver a próxima conta...");
        getch(); // Espera o usuário pressionar uma tecla
        
        // Limpa a tela antes de exibir a próxima conta
        system("cls");
        desenhar_tela(); // Redesenha o layout

        atual = atual->proximo; // Move para o próximo nó
    }

    getch(); // Aguarda o usuário pressionar uma tecla para voltar ao menu
    menucontasbancarias();
}
