#include "funcoes.h"

void ConsultarOrdemCodigoContas(TipoLista *L) {
    system("cls");  
    desenhar_tela();

    tipoApontador p, q; 
    reg_ContaBanco temp;

    // Verifica se a lista está vazia, ou seja, não há contas cadastradas.
    if (L->Primeiro == NULL) {
        gotoxy(7, 7);  
        printf("Nao existem contas cadastradas.\n");
        getch();  
        return;  
    }
    for (p = L->Primeiro; p != NULL; p = p->proximo) {
        for (q = p->proximo; q != NULL; q = q->proximo) {
            if (p->conteudo.codigo > q->conteudo.codigo) {  
                // Se o código de p for maior que o de q, troca os conteúdos das contas.
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    // Inicia o ponteiro p com a primeira conta da lista após a ordenação.
    p = L->Primeiro;

    // Exibe as contas uma a uma, começando pela primeira.
    while (p != NULL) {
        system("cls");  
        desenhar_tela(); 

        // Exibe os dados da conta de forma detalhada na tela, linha por linha.
        gotoxy(7, 7);
        printf("Codigo: %d\n", p->conteudo.codigo);  // Exibe o código da conta.
        gotoxy(7, 8);
        printf("Banco: %s\n", p->conteudo.Banco);  // Exibe o nome do banco.
        gotoxy(7, 9);
        printf("Agencia: %d\n", p->conteudo.agencia);  // Exibe o número da agência.
        gotoxy(7, 10);
        printf("Numero da Conta: %d\n", p->conteudo.numConta);  // Exibe o número da conta.
        gotoxy(7, 11);
        printf("Tipo da Conta: %s\n", p->conteudo.tipo_conta);  // Exibe o tipo da conta.
        gotoxy(7, 12);
        printf("Saldo: %.2f\n", p->conteudo.saldo);  // Exibe o saldo da conta.
        gotoxy(7, 13);
        printf("Limite: %.2f\n", p->conteudo.Limite);  // Exibe o limite da conta.
        gotoxy(7, 14);
        printf("Status da Conta: %d\n", p->conteudo.statusConta);  // Exibe o status da conta.

        gotoxy(7, 23);
        printf("Pressione qualquer tecla para ver a proxima conta...\n"); 
        getch(); 

        p = p->proximo;  // Avança para a próxima conta na lista.
    }

    menucontasbancarias();  
}
