#include "funcoes.h"
void movimentacaoDebitoCredito(TipoLista *L) {
    int opcao;
    int contaSelecionada;
    reg_ContaBanco conta;
    tipoApontador p;
    
    desenhar_tela();
    
    // Solicitar o código da conta para movimentação
    gotoxy(7, 5);
    printf("Digite o codigo da conta: ");
    scanf("%d", &contaSelecionada);
    
    // Procurar a conta no banco de dados
    p = L->Primeiro;
    while (p != NULL) {
        if (p->conteudo.codigo == contaSelecionada) {
            conta = p->conteudo;
            break;
        }
        p = p->proximo;
    }
    
    if (p == NULL) {
        gotoxy(7, 9);
        printf("Conta nao encontrada.\n");
        getch();
        menumovibancarias();
        return;
    }

    // Exibir informações da conta
    gotoxy(7, 6);
    printf("Codigo da Conta........: %d", conta.codigo);
    gotoxy(7, 7);
    printf("Banco..................: %s", conta.Banco);
    gotoxy(7, 8);
    printf("Agencia................: %d", conta.agencia);
    gotoxy(7, 9);
    printf("Numero da Conta........: %d", conta.numConta);
    gotoxy(7, 10);
    printf("Tipo da Conta..........: %s", conta.tipo_conta);
    gotoxy(7, 11);
    printf("Saldo..................: %.2f", conta.saldo);
    gotoxy(7, 12);
    printf("Limite.................: %.2f", conta.Limite);
    gotoxy(7, 13);
    printf("Total Saldo + Limite...: %.2f", conta.saldo + conta.Limite);

    // Solicitar movimentação
    gotoxy(7, 14);
    printf("1-Data Movimentacao....: ");
    char dataMovimentacao[20];
    fflush(stdin);
    fgets(dataMovimentacao, 20, stdin);
    
    gotoxy(7, 15);
    printf("2-Tipo Movimentacao....: ");
    gotoxy(7, 16);
    printf("1 - Debito    2 - Credito:");
    scanf("%d", &opcao);
    
    gotoxy(7, 17);
    printf("3-Favorecido...........: ");
    int codigoFavorecido;
    scanf("%d", &codigoFavorecido);

    gotoxy(7, 18);
    printf("4-Valor Movimentacao...: ");
    float valorMovimentacao;
    scanf("%f", &valorMovimentacao);

    // Verificar se o valor da movimentação é positivo
    if (valorMovimentacao <= 0) {
        gotoxy(7, 23);
        printf("Valor de movimentacao invalido.\n");
        getch();
        return;
    }

    // Realizar a movimentação
    if (opcao == 1) {
        // Débito
        if (conta.saldo + conta.Limite >= valorMovimentacao) {
            conta.saldo -= valorMovimentacao;  // Subtrai o valor da conta de origem (conta 1)

            // Encontra a conta do favorecido
            tipoApontador pFavorecido = L->Primeiro;
            while (pFavorecido != NULL) {
                if (pFavorecido->conteudo.codigo == codigoFavorecido) {
                    pFavorecido->conteudo.saldo += valorMovimentacao;  // Adiciona o valor à conta do favorecido
                    break;
                }
                pFavorecido = pFavorecido->proximo;
            }
            if (pFavorecido == NULL) {
                gotoxy(7, 23);
                printf("Favorecido nao encontrado.\n");
                conta.saldo += valorMovimentacao;  // Se não encontrado, desfaz o débito
                getch();
                return;
            }
        } else {
            gotoxy(7, 23);
            printf("Saldo insuficiente.\n");
            gotoxy(7, 24);
            printf("Saldo atual: %.2f\n", conta.saldo);
            getch();
            return;
        }
    } else if (opcao == 2) {
        // Crédito
        conta.saldo += valorMovimentacao;  // Adiciona o valor à conta de origem
        
        // Encontra a conta do favorecido
        tipoApontador pFavorecido = L->Primeiro;
        while (pFavorecido != NULL) {
            if (pFavorecido->conteudo.codigo == codigoFavorecido) {
                pFavorecido->conteudo.saldo += valorMovimentacao;  // Adiciona o valor à conta do favorecido
                break;
            }
            pFavorecido = pFavorecido->proximo;
        }
        if (pFavorecido == NULL) {
            gotoxy(7, 23);
            printf("Favorecido nao encontrado.\n");
            getch();
            return;
        }
    }

    // Exibir novo saldo
    gotoxy(7, 19);
    printf("5-Novo Saldo...........: %.2f", conta.saldo);
    getch();

    // Atualiza a conta no banco de dados
    p->conteudo = conta;
    gravar_contas(L); // Grava os dados atualizados

    // Volta ao menu principal
    menumovibancarias();
}
