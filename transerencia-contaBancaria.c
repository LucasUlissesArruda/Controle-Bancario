/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/
#include "funcoes.h"
void TransferirEntreContas(TipoLista *L) {
    system("cls");
    desenhar_tela();

    int codigoOrigem, codigoDestino;
    float valorTransferencia;
    tipoApontador contaOrigem = NULL, contaDestino = NULL;
    Movimentacao movi;

    // enfeite
    gotoxy(2, 5);
    printf("----------- CONTA ORIGEM -----------+----------- CONTA DESTINO --------------");

    // pede o codigo de origem
    gotoxy(7, 7);
    printf("Conta de Origem: ");
    scanf("%d", &codigoOrigem);

    // acha o codigo de origem
    contaOrigem = L->Primeiro;
    while (contaOrigem != NULL && contaOrigem->conteudo.codigo != codigoOrigem) {
        contaOrigem = contaOrigem->proximo;
    }

    // se nao achar tem isso aqui
    if (contaOrigem == NULL) {
        gotoxy(7, 8);
        printf("Conta de origem nao encontrada!");
        getch();
        menumovibancarias();
        return;
    }

    // pede o codigo de destino
    gotoxy(50, 7);
    printf("Conta de Destino: ");
    scanf("%d", &codigoDestino);

    // procura o codigo
    contaDestino = L->Primeiro;
    while (contaDestino != NULL && contaDestino->conteudo.codigo != codigoDestino) {
        contaDestino = contaDestino->proximo;
    }

    // novamente se não tiver
    if (contaDestino == NULL) {
        gotoxy(50, 8);
        printf("Conta de destino nao encontrada!");
        getch();
        menumovibancarias();
        return;
    }

    // mostra lado a lado(deu trabalho)
    gotoxy(7, 10);
    printf("Banco..........: %s", contaOrigem->conteudo.Banco);
    gotoxy(50, 10);
    printf("Banco..........: %s", contaDestino->conteudo.Banco);

    gotoxy(7, 11);
    printf("Agencia........: %d", contaOrigem->conteudo.agencia);
    gotoxy(50, 11);
    printf("Agencia........: %d", contaDestino->conteudo.agencia);

    gotoxy(7, 12);
    printf("Numero da Conta: %d", contaOrigem->conteudo.numConta);
    gotoxy(50, 12);
    printf("Numero da Conta: %d", contaDestino->conteudo.numConta);

    gotoxy(7, 13);
    printf("Tipo da Conta..: %s", contaOrigem->conteudo.tipo_conta);
    gotoxy(50, 13);
    printf("Tipo da Conta..: %s", contaDestino->conteudo.tipo_conta);

    gotoxy(7, 14);
    printf("Saldo..........: %.2f", contaOrigem->conteudo.saldo);
    gotoxy(50, 14);
    printf("Saldo..........: %.2f", contaDestino->conteudo.saldo);

    gotoxy(7, 15);
    printf("Limite.........: %.2f", contaOrigem->conteudo.Limite);
    gotoxy(50, 15);
    printf("Limite.........: %.2f", contaDestino->conteudo.Limite);

    // pede o valor
    gotoxy(7, 18);
    printf("Valor a ser transferido: ");
    scanf("%f", &valorTransferencia);

    // ve se tem dinheiro suficiente na conta
    if (contaOrigem->conteudo.saldo + contaOrigem->conteudo.Limite < valorTransferencia) {
        gotoxy(7, 19);
        printf("Saldo insuficiente na conta de origem!");
        getch();
        menumovibancarias();
        return;
    }

    // faz a transferencia
    contaOrigem->conteudo.saldo -= valorTransferencia;
    contaDestino->conteudo.saldo += valorTransferencia;

    // mostra os novos saldos (bglh foi chato)
    gotoxy(7, 17);
    printf("Novo Saldo.....: %.2f", contaOrigem->conteudo.saldo);
    gotoxy(50, 17);
    printf("Novo Saldo.....: %.2f", contaDestino->conteudo.saldo);

    //pede a data
    gotoxy(7, 20);
    printf("Data da Transferencia (dd/mm/aaaa): ");
    scanf("%c", movi.data);

    // se deus quiser chega aqui
    gotoxy(7, 23);
    printf("Transferencia realizada com sucesso!");
    getch();
    menumovibancarias();
}
