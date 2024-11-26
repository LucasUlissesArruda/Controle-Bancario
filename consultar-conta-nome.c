#include "funcoes.h"

void ConsultarOrdemAlfabeticaContas(TipoLista *L) {
    system("cls");
    desenhar_tela();

    tipoApontador p, q;
    reg_ContaBanco temp;
    
    if (L->Primeiro == NULL) {
        gotoxy(7, 7);
        printf("Nao existem contas cadastradas.\n");
        getch();
        return;
    }

    for (p = L->Primeiro; p != NULL; p = p->proximo) {
        for (q = p->proximo; q != NULL; q = q->proximo) {
            if (strcmp(p->conteudo.Banco, q->conteudo.Banco) > 0) {
                
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    
    gotoxy(7, 7);
    printf("Contas Bancarias em Ordem Alfabética:\n");
    p = L->Primeiro;
    int linha = 9;

    while (p != NULL) {
        gotoxy(7, linha++);
        printf("Codigo: %d | Banco: %s | Agencia: %d | Conta: %d | Tipo: %s | Saldo: %.2f | Limite: %.2f | Status: %d\n",
               p->conteudo.codigo,
               p->conteudo.Banco,
               p->conteudo.agencia,
               p->conteudo.numConta,
               p->conteudo.tipo_conta,
               p->conteudo.saldo,
               p->conteudo.Limite,
               p->conteudo.statusConta);
        p = p->proximo;
    }

    gotoxy(2, linha);
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    getch(); 

    menucontasbancarias(); 
}
