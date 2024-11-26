#include "funcoes.h"

void ConsultarOrdemCodigoContas(TipoLista *L) {
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
            if (p->conteudo.codigo > q->conteudo.codigo) {
              
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    
    p = L->Primeiro;
    while (p != NULL) {
        system("cls");  
        desenhar_tela();  
        
        gotoxy(7, 7);
        printf("Codigo: %d\n", p->conteudo.codigo);
        gotoxy(7, 8);
        printf("Banco: %s\n", p->conteudo.Banco);
        gotoxy(7, 9);
        printf("Agencia: %d\n", p->conteudo.agencia);
        gotoxy(7, 10);
        printf("Numero da Conta: %d\n", p->conteudo.numConta);
        gotoxy(7, 11);
        printf("Tipo da Conta: %s\n", p->conteudo.tipo_conta);
        gotoxy(7, 12);
        printf("Saldo: %.2f\n", p->conteudo.saldo);
        gotoxy(7, 13);
        printf("Limite: %.2f\n", p->conteudo.Limite);
        gotoxy(7, 14);
        printf("Status da Conta: %d\n", p->conteudo.statusConta);

        gotoxy(7, 23);  
        printf("Pressione qualquer tecla para ver a proxima conta...\n");
        getch();  

        p = p->proximo;  
    }

    menucontasbancarias();  
}
