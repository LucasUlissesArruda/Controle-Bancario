/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/

#include "funcoes.h"

void movimentacaoDebitoCredito(TipoLista *L) {
    int opcao;
    int contaSelecionada;
    reg_ContaBanco conta;
    tipoApontador p;
    Movimentacao movi;
    int codigoFavorecido;
    float valorMovimentacao;

    desenhar_tela();

    // pede o codigo do individuo
    gotoxy(7, 5);
    printf("Digite o codigo da conta: ");
    scanf("%d", &contaSelecionada);

    // ele procura o individuo
    p = L->Primeiro;
    while (p != NULL) {
        if (p->conteudo.codigo == contaSelecionada) {
            conta = p->conteudo;
            break;
        }
        p = p->proximo;
    }

    // nao achou :(
    if (p == NULL) {
        gotoxy(7, 9);
        printf("Conta nao encontrada");
        getch();
        menumovibancarias();
        return;
    }

    // ve se a conta ainda pode fazer a transação
    if (conta.statusConta == 0) {
        gotoxy(7, 23);
        printf("Conta inativa. Transacao nao permitida");
        getch();
        menumovibancarias();
        return;
    }

    // mostra as informações
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

    // verifica se da para fazer a transação
    if (conta.saldo + conta.Limite <= 0) {
        gotoxy(7, 23);
        printf("Saldo e limite insuficientes para transacao");
        getch();
        menumovibancarias();
        return;
    }

    // pede a movimentação
    gotoxy(7, 14);
    printf("1-Data Movimentacao....: ");
    fflush(stdin);
    scanf("%c", movi.data);

    gotoxy(7, 15);
    printf("2-Tipo Movimentacao....: ");
    gotoxy(7, 16);
    printf("1 - Debito    2 - Credito:");
    scanf("%d", &opcao);

    // sortudo que ganha o dinero
    gotoxy(7, 17);
    printf("3-Favorecido...........: ");
    scanf("%d", &codigoFavorecido);

    gotoxy(7, 18);
    printf("4-Valor Movimentacao...: ");
    scanf("%f", &valorMovimentacao);

    // ve se tem dinheiro na carteira
    if (valorMovimentacao <= 0) {
        gotoxy(7, 23);
        printf("Valor de movimentacao invalido");
        getch();
        menumovibancarias();
        return;
    }

    // teve dinheiro
    if (opcao == 1) {  // Débito
        if (conta.saldo > 0) {
            // se tiver ele tira
            conta.saldo -= valorMovimentacao;
        } else if (conta.saldo == 0) {
            // se não tiver vem no limite
            if (conta.Limite >= valorMovimentacao) {
                conta.Limite -= valorMovimentacao;
            } else {
                gotoxy(7, 23);
                printf("Limite insuficiente");
                getch();
                menumovibancarias();
                return;
            }
        } else {
            // se não estiver tendo nenhum dos dois
            gotoxy(7, 23);
            printf("Saldo insuficiente");
            gotoxy(7, 24);
            printf("Saldo atual: %.2f\n", conta.saldo);
            getch();
            menumovibancarias();
            return;
        }

        // acha o favorecido
        tipoApontador pFavorecido = L->Primeiro;
        while (pFavorecido != NULL) {
            if (pFavorecido->conteudo.codigo == codigoFavorecido) {
                pFavorecido->conteudo.saldo += valorMovimentacao;  // coloca dinheiro la
                break;
            }
            pFavorecido = pFavorecido->proximo;
        }
        if (pFavorecido == NULL) {
            gotoxy(7, 23);
            printf("Favorecido nao encontrado");
            conta.saldo += valorMovimentacao;  // não achou volta o din
            conta.Limite += valorMovimentacao;
            getch();
            movimentacaoDebitoCredito(L);
            return;
        }

    } else if (opcao == 2) {  // Crédito
        conta.saldo -= valorMovimentacao;  // tira da conta de origem

        // acha o favorecido
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
            printf("Favorecido nao encontrado");
            getch();
            menumovibancarias();
            return;
        }
    }

    // Exibir novo saldo
    gotoxy(7, 19);
    printf("5-Novo Saldo...........: %.2f", conta.saldo);
    gotoxy(7, 20);
    printf("6-Novo Limite..........: %.2f", conta.Limite);
    getch();

    // atualiza os saldos
    p->conteudo = conta;
    gravar_movi(L);
    menumovibancarias();
}
