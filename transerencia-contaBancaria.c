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

    gotoxy(2,17);
    printf("-----------------------------------------------------------------------------");

    // pede o código de origem
    gotoxy(7, 7);
    printf("Conta de Origem: ");
    scanf("%d", &codigoOrigem);

    // acha o código de origem
    contaOrigem = L->Primeiro;
    while (contaOrigem != NULL && contaOrigem->conteudo.codigo != codigoOrigem) {
        contaOrigem = contaOrigem->proximo;
    }

    // se não achar
    if (contaOrigem == NULL) {
        gotoxy(7, 8);
        printf("Conta de origem nao encontrada!");
        getch();
        menumovibancarias();
        return;
    }

    // verifica se a conta de origem está ativa
    if (contaOrigem->conteudo.statusConta == 0) {
        gotoxy(7, 23);
        printf("Conta origem inativa. Transacao nao permitida!");
        getch();
        menumovibancarias();
        return;
    }

    // pede o código de destino
    gotoxy(50, 7);
    printf("Conta de Destino: ");
    scanf("%d", &codigoDestino);

    if(contaOrigem->conteudo.codigo  == codigoDestino){
        gotoxy(7,23);
        printf("Nao pode mandar para a mesma conta");
        getch();
        menumovibancarias();
    }


    // procura o código
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

    // verifica se a conta de destino está ativa
    if (contaDestino->conteudo.statusConta == 0) {
        gotoxy(7, 23);
        printf("Conta destino inativa. Transacao nao permitida!");
        getch();
        menumovibancarias();
        return;
    }

    // mostra lado a lado
    gotoxy(7, 10);
    printf("Banco: %s", contaOrigem->conteudo.Banco);
    gotoxy(45, 10);
    printf("Banco: %s", contaDestino->conteudo.Banco);

    gotoxy(7, 11);
    printf("Agencia: %d", contaOrigem->conteudo.agencia);
    gotoxy(45, 11);
    printf("Agencia: %d", contaDestino->conteudo.agencia);

    gotoxy(7, 12);
    printf("Numero da Conta: %d", contaOrigem->conteudo.numConta);
    gotoxy(45, 12);
    printf("Numero da Conta: %d", contaDestino->conteudo.numConta);

    gotoxy(7, 13);
    printf("Tipo da Conta: %s", contaOrigem->conteudo.tipo_conta);
    gotoxy(45, 13);
    printf("Tipo da Conta: %s", contaDestino->conteudo.tipo_conta);

    gotoxy(7, 14);
    printf("Saldo: %.2f", contaOrigem->conteudo.saldo);
    gotoxy(45, 14);
    printf("Saldo: %.2f", contaDestino->conteudo.saldo);

    gotoxy(7, 15);
    printf("Limite: %.2f", contaOrigem->conteudo.Limite);
    gotoxy(45, 15);
    printf("Limite: %.2f", contaDestino->conteudo.Limite);

    

    // pede o valor
    gotoxy(7, 18);
    printf("Valor a ser transferido: ");
    scanf("%f", &valorTransferencia);

    // verifica se tem dinheiro suficiente na conta
    if (contaOrigem->conteudo.saldo + contaOrigem->conteudo.Limite < valorTransferencia) {
        gotoxy(7, 23);
        printf("Saldo insuficiente na conta de origem!");
        getch();
        menumovibancarias();
        return;
    }

    // faz a transferência
    contaOrigem->conteudo.saldo = contaOrigem->conteudo.saldo - valorTransferencia;
    contaDestino->conteudo.saldo = contaDestino->conteudo.saldo + valorTransferencia;

    // mostra os novos saldos
    gotoxy(7, 20);
    printf("Novo Saldo Origem: %.2f", contaOrigem->conteudo.saldo);
    gotoxy(40, 20);
    printf("Novo Saldo Destino: %.2f", contaDestino->conteudo.saldo);

    // pede a data
    gotoxy(7, 23);
    printf("Data da Transferencia (dd/mm/aaaa): ");
    scanf("%s", movi.data);

    if (!validaData(movi.data)) {
        gotoxy(7, 23);
        printf("Data invalida. Digite no formato dd/mm/aaaa.");
        getch();
        menumovibancarias();
        return;
    }

    // registra a movimentação
    movi.valor = valorTransferencia;
    strcpy(movi.tipoMov, "Transferencia");
    gravar_movi(L);

    gotoxy(7, 23);
    printf("Transferencia realizada com sucesso!");
    getch();
    menumovibancarias();
}
