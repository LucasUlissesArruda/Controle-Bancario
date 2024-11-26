#include "funcoes.h"
void TransferirEntreContas(TipoLista *L) {
    system("cls");
    desenhar_tela();

    int codigoOrigem, codigoDestino;
    float valorTransferencia;
    tipoApontador contaOrigem = NULL, contaDestino = NULL;

    // Cabeçalho
    gotoxy(2, 5);
    printf("----------- CONTA ORIGEM -----------+----------- CONTA DESTINO --------------");

    // Solicitar código da conta de origem
    gotoxy(7, 7);
    printf("Conta de Origem: ");
    scanf("%d", &codigoOrigem);

    // Buscar conta de origem
    contaOrigem = L->Primeiro;
    while (contaOrigem != NULL && contaOrigem->conteudo.codigo != codigoOrigem) {
        contaOrigem = contaOrigem->proximo;
    }

    if (contaOrigem == NULL) {
        gotoxy(7, 8);
        printf("Conta de origem nao encontrada!");
        getch();
        menumovibancarias();
        return;
    }

    // Solicitar código da conta de destino
    gotoxy(50, 7);
    printf("Conta de Destino: ");
    scanf("%d", &codigoDestino);

    // Buscar conta de destino
    contaDestino = L->Primeiro;
    while (contaDestino != NULL && contaDestino->conteudo.codigo != codigoDestino) {
        contaDestino = contaDestino->proximo;
    }

    if (contaDestino == NULL) {
        gotoxy(50, 8);
        printf("Conta de destino nao encontrada!");
        getch();
        menumovibancarias();
        return;
    }

    // Exibir informações lado a lado
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

    // Solicitar valor da transferência
    gotoxy(7, 18);
    printf("Valor a ser transferido: ");
    scanf("%f", &valorTransferencia);

    // Validar transferência
    if (contaOrigem->conteudo.saldo + contaOrigem->conteudo.Limite < valorTransferencia) {
        gotoxy(7, 19);
        printf("Saldo insuficiente na conta de origem!");
        getch();
        menumovibancarias();
        return;
    }

    // Realizar transferência
    contaOrigem->conteudo.saldo -= valorTransferencia;
    contaDestino->conteudo.saldo += valorTransferencia;

    // Exibir novos saldos
    gotoxy(7, 17);
    printf("Novo Saldo.....: %.2f", contaOrigem->conteudo.saldo);
    gotoxy(50, 17);
    printf("Novo Saldo.....: %.2f", contaDestino->conteudo.saldo);

    // Solicitar data da transferência
    char dataTransferencia[11];
    gotoxy(7, 20);
    printf("Data da Transferencia (dd/mm/aaaa): ");
    scanf("%s", dataTransferencia);

    gotoxy(7, 23);
    printf("Transferencia realizada com sucesso!");
    getch();
    menumovibancarias();
}
