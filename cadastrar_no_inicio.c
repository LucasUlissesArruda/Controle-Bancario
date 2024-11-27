/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/
#include "funcoes.h"

void CadastrarContaInicio(TipoLista *L) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador p;
    int opcaoTipoConta;

    // quer cancelar ?
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
    printf("Digite o número da conta: ");
    scanf("%d", &conta.numConta);

    // Menu de seleção do tipo de conta
    gotoxy(7,11);
    printf("Escolha o tipo de conta:\n");
    gotoxy(7,12);
    printf("1 - Conta Corrente\n");
    gotoxy(7,13);
    printf("2 - Conta Poupanca\n");
    gotoxy(7,14);
    printf("3 - Cartao de Credito\n");

    gotoxy(7,15);
    printf("Escolha a opcao: ");
    scanf("%d", &opcaoTipoConta);

    // aqui ele muda a sua opção de numero para escrita
    if (opcaoTipoConta == 1) {
        strcpy(conta.tipo_conta, "Corrente");
    } else if (opcaoTipoConta == 2) {
        strcpy(conta.tipo_conta, "Poupanca");
    } else if (opcaoTipoConta == 3) {
        strcpy(conta.tipo_conta, "Cartao de Credito");
    } else { // escolhe direito
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

    // coloca os dados em um novo nó
    p->conteudo = conta;

    // atualiza o ponteiro para primeiro
    if (L->Primeiro == NULL) { // Lista vazia
        p->proximo = NULL;
        L->Primeiro = p;
        L->Ultimo = p;
    } else {
        p->proximo = L->Primeiro; // ele aponta para o antigo primeiro
        L->Primeiro = p;         // aqui ele vira o primeiro nó
    }



    // amém irmão
    gotoxy(7, 23);
    printf("Conta cadastrada no início com sucesso!\n");
    getch();
    gravar_contas(L);
    menucontasbancarias(); 
}