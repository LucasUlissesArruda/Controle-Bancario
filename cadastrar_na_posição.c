#include "funcoes.h"

void CadastrarContaPosicao(TipoLista *L) {
    system("cls");
    desenhar_tela();

    reg_ContaBanco conta;
    tipoApontador novo, anterior, atual;
    int posicao, contador = 1;

    gotoxy(7, 23);
    printf("Digite 0 para cancelar a operacao.\n");

    

    // Solicita os dados da nova conta
    gotoxy(7, 7);
    printf("Codigo: ");
    scanf("%d", &conta.codigo);

    gotoxy(7, 23);
    printf("                                                               ");

    // Verificar se o código é 0 para cancelar
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

    gotoxy(7, 17);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    gotoxy(7, 18);
    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

    gotoxy(7, 19);
    printf("Digite o status da conta (0 - Inativa, 1 - Ativa): ");
    scanf("%d", &conta.statusConta);

    // Solicita a posição para cadastro
    gotoxy(7, 20);
    printf("Digite a posição para cadastrar (iniciando de 1): ");
    scanf("%d", &posicao);

    // Verificar se a posição é 0 para cancelar
    if (posicao == 0) {
        menucontasbancarias();
        return;
    }

    // Cria o novo nó
    novo = (tipoApontador)malloc(sizeof(TipoItem));
    if (novo == NULL) {
        gotoxy(7, 23);
        printf("Erro de memória ao cadastrar conta!");
        getch();
        return;
    }
    novo->conteudo = conta;
    novo->proximo = NULL;

    // Inserção na posição
    if (posicao == 1) {
        // Inserção no início
        novo->proximo = L->Primeiro;
        L->Primeiro = novo;
        if (L->Ultimo == NULL) {
            L->Ultimo = novo;
        }
        gotoxy(7, 23);
        printf("Conta cadastrada na posição 1 (início).\n");
    } else {
        // Inserção em posição intermediária ou no final
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
            int confirmacao;
            scanf("%d", &confirmacao);
            if (confirmacao == 0) {
                free(novo);
                gotoxy(7, 21);
                printf("Operacao cancelada.\n");
                getch();
                return;
            }
        } else {
            // Inserção intermediária
            novo->proximo = atual;
            if (anterior != NULL) {
                anterior->proximo = novo;
            }
        }

        gotoxy(7, 23);
        printf("Conta cadastrada na posição %d.\n", posicao);
    }

    // Atualiza o último nó, caso necessário
    if (novo->proximo == NULL) {
        L->Ultimo = novo;
    }

    // Pausa e retorna ao menu
    getch();
    menucontasbancarias();
}
