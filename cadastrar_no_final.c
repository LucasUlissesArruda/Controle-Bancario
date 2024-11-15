#include "Funcoes.h"
#include <conio.h>

void CadastrarContaFinal(TipoLista *L) {
    reg_ContaBanco conta;
    tipoApontador p;

    printf("Digite o código: ");
    scanf("%d", &conta.codigo);

    printf("Digite o nome do banco: ");
    fflush(stdin);
    fgets(conta.Banco, 50, stdin);
    conta.Banco[strcspn(conta.Banco, "\n")] = '\0';

    printf("Digite a agência: ");
    scanf("%d", &conta.agencia);

    printf("Digite o número da conta: ");
    scanf("%d", &conta.numConta);

    printf("Digite o tipo de conta: ");
    fflush(stdin);
    fgets(conta.tipo_conta, 50, stdin);
    conta.tipo_conta[strcspn(conta.tipo_conta, "\n")] = '\0';

    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

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
    p->proximo = NULL;

    // Atualiza os ponteiros da lista
    if (L->Primeiro == NULL) {
        L->Primeiro = p;
        L->Ultimo = p;
    } else {
        L->Ultimo->proximo = p;
        L->Ultimo = p;
    }

    printf("Conta cadastrada no final com sucesso!\n");
}