#include "funcoes.h"

void CadastrarContaPosicao(TipoLista *L) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador novo, anterior, atual;
    int posicao, contador = 1;
    int opcaoTipoConta;
    int confirmacao;

    // quer não ?
    gotoxy(7, 23);
    printf("Digite 0 para cancelar a operacao.\n");

    // pede os novos dados da conta
    gotoxy(7, 7);
    printf("Codigo: ");
    scanf("%d", &conta.codigo);

    gotoxy(7, 23);
    printf("                                                               ");

    // se digitar 0 ele cancela
    if (conta.codigo == 0) {
        menucontasbancarias();
        return;
    }

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

    // Menu de seleção do tipo de conta
    gotoxy(7, 11);
    printf("Escolha o tipo de conta:\n");
    gotoxy(7, 12);
    printf("1 - Conta Corrente\n");
    gotoxy(7, 13);
    printf("2 - Conta Poupanca\n");
    gotoxy(7, 14);
    printf("3 - Cartao de Credito\n");

    gotoxy(7, 15);
    printf("Escolha a opcao: ");

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

    gotoxy(7, 17);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    gotoxy(7, 18);
    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

    gotoxy(7, 19);
    printf("Digite o status da conta (0 - Inativa, 1 - Ativa): ");
    scanf("%d", &conta.statusConta);

    // pergunta aonde quer colocar
    gotoxy(7, 20);
    printf("Digite a posição para cadastrar (iniciando de 1): ");
    scanf("%d", &posicao);

    // se digitar 0 cancela
    if (posicao == 0) {
        menucontasbancarias();
        return;
    }

    novo = (tipoApontador)malloc(sizeof(TipoItem));
    if (novo == NULL) {
        gotoxy(7, 23);
        printf("Erro ao alocar memoria");
        getch();
        return;
    }

    novo->conteudo = conta;
    novo->proximo = NULL;

    // Inserção na posição
    if (posicao == 1) {
        // coloca no inicio ainda
        novo->proximo = L->Primeiro;
        L->Primeiro = novo;
        if (L->Ultimo == NULL) {
            L->Ultimo = novo;
        }
        gotoxy(7, 23);
        printf("Conta cadastrada na posição 1 (início).\n");
    } else {
        // coloca aonde você quiser ou no final
        anterior = NULL;
        atual = L->Primeiro;
        while (contador < posicao && atual != NULL) {
            anterior = atual;
            atual = atual->proximo;
            contador++;
        }

        if (atual == NULL) {
            // Caso a posição seja no final
            if (anterior != NULL) {
                anterior->proximo = novo;
            }
            L->Ultimo = novo;
            gotoxy(7, 23);
            printf("Posicao %d é a última. Deseja cadastrar aqui? (1-Sim, 0-Nao): ", contador);
            scanf("%d", &confirmacao);
            if (confirmacao == 0) {
                free(novo);
                gotoxy(7, 21);
                printf("Operacao cancelada.\n");
                getch();
                return;
            }
        } else {
            // coloca em algum lugar
            novo->proximo = atual;
            if (anterior != NULL) {
                anterior->proximo = novo;
            }
        }


        gotoxy(7, 23);
        printf("Conta cadastrada na posição %d.\n", posicao);
    }

    // atualiza o nó se precisar
    if (novo->proximo == NULL) {
        L->Ultimo = novo;
    }
    getch();
    menucontasbancarias();
}