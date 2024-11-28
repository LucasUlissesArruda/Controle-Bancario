/*
Autor: Leonardo Henrique
RA: Aluno 1: 179114-2024 Lucas Ulisses
    Aluno 2: 153939-2023
Data: 25/11/2024
*/
#include "funcoes.h"

void CadastrarContaFinal(TipoLista *L) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador p;

    gotoxy(7,23);
    printf("Digite 0 Para Cancelar a Operacao");

    gotoxy(7,7);
    printf("Codigo: ");
    scanf("%d", &conta.codigo);

    gotoxy(7, 23);
    printf("                                                               ");
    if(conta.codigo == 0){
        menucontasbancarias();
        return;
    }

    gotoxy(7,8);
    printf("Nome do banco: ");
    fflush(stdin);
    fgets(conta.Banco, 50, stdin);

    gotoxy(7,9);
    printf("Digite a agencia: ");
    scanf("%d", &conta.agencia);

    gotoxy(7,10);
    printf("Digite o numero da conta: ");
    scanf("%d", &conta.numConta);

    // Menu de seleção do tipo de conta
    gotoxy(7,11);
    printf("Escolha o tipo de conta:");
    gotoxy(7,12);
    printf("1 - Conta Corrente");
    gotoxy(7,13);
    printf("2 - Conta Poupanca");
    gotoxy(7,14);
    printf("3 - Cartao de Credito");

    gotoxy(7,15);
    printf("Escolha a opcao: ");
    int opcaoTipoConta;
    scanf("%d", &opcaoTipoConta);

    if (opcaoTipoConta == 1) {
        strcpy(conta.tipo_conta, "Corrente");
    } else if (opcaoTipoConta == 2) {
        strcpy(conta.tipo_conta, "Poupanca");
    } else if (opcaoTipoConta == 3) {
        strcpy(conta.tipo_conta, "Cartao de Credito");
    } else {
        gotoxy(7, 16);
        printf("Opcao invalida! Tipo de conta nao cadastrado.\n");
        getch();
        return;
    }

    gotoxy(7,17);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    gotoxy(7,18);
    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

    gotoxy(2,23);
    printf("Digite o status da conta (0 - Inativa, 1 - Ativa): ");
    scanf("%d", &conta.statusConta);

    p = (tipoApontador)malloc(sizeof(TipoItem));
    if (p == NULL) {
        gotoxy(7, 23);
        printf("Erro ao alocar memoria");
        getch();
        return;
    }

    // Insere os dados no novo nó
    p->conteudo = conta;
    p->proximo = NULL;

    // Atualiza os ponteiros da lista
    if (L->Primeiro == NULL) {
        L->Primeiro = p;
        L->Ultimo = p;
    } else {
        L->Ultimo->proximo = p;
        L->Ultimo = p;
    }

    gotoxy(02,23);
    printf("                                                             ");

    gotoxy(7, 23);
    printf("Conta cadastrada no final com sucesso!");
    getch(); // Pausa para o usuário ver a mensagem

    gravar_contas(L); // Grava os dados da lista no arquivo
    menucontasbancarias(); // Volta ao menu
}