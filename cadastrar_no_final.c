#include "Funcoes.h"
#include <conio.h>

void CadastrarContaFinal(TipoLista *L) {
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
    conta.Banco[strcspn(conta.Banco, "\n")] = '\0';

    gotoxy(7,9);
    printf("Digite a agência: ");
    scanf("%d", &conta.agencia);

    gotoxy(7,10);
    printf("Digite o número da conta: ");
    scanf("%d", &conta.numConta);

    gotoxy(7,11);
    printf("Digite o tipo de conta: ");
    fflush(stdin);
    fgets(conta.tipo_conta, 50, stdin);
    conta.tipo_conta[strcspn(conta.tipo_conta, "\n")] = '\0';

    gotoxy(7,12);
    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    gotoxy(7,13);
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