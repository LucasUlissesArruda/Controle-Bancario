#include "funcoes.h"

void CadastrarContaInicio(TipoLista *L) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador p;

    gotoxy(7,7);
    printf("Codigo: ");
    scanf("%d", &conta.codigo);
    
    gotoxy(7,8);
    printf("Nome do banco: ");
    fflush(stdin);
    fgets(conta.Banco, 50, stdin);

    gotoxy(7,9);
    printf("Digite a agência: ");
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

    // Aloca memória para o novo nó
    p = (tipoApontador)malloc(sizeof(TipoItem));
    if (p == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }

    // Insere os dados no novo nó
    p->conteudo = conta;

    // Atualiza os ponteiros para inserir no início
    if (L->Primeiro == NULL) { // Lista vazia
        p->proximo = NULL;
        L->Primeiro = p;
        L->Ultimo = p;
    } else {
        p->proximo = L->Primeiro; // Novo nó aponta para o antigo primeiro nó
        L->Primeiro = p;         // Novo nó se torna o primeiro
    }

    gotoxy(7, 19);
    printf("Conta cadastrada no início com sucesso!\n");
    getch(); // Pausa para o usuário ver a mensagem

    gravar_contas(L); // Grava a conta no arquivo


    menucontasbancarias();  // Volta ao menu de contas bancárias
}
