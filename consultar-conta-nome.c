/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/
#include "funcoes.h"

void ConsultarOrdemAlfabeticaContas(TipoLista *L) {
    system("cls");  
    desenhar_tela();  

    tipoApontador p, q;  
    reg_ContaBanco temp; 

    // Vve se tem alguem na bagaça
    if (L->Primeiro == NULL) {
        gotoxy(7, 7);  
        printf("Nao existem contas cadastradas.\n"); 
        getch();  
        return;
    }

    // ordena os bancos 
    for (p = L->Primeiro; p != NULL; p = p->proximo) {  // olha cada elemento da lista
        for (q = p->proximo; q != NULL; q = q->proximo) {  // ve os elementos seguintes tb
            if (strcmp(p->conteudo.Banco, q->conteudo.Banco) > 0) {  // compara os nomes
                // muda se tiver fora de ordem
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    // mostra em ordem
    gotoxy(7, 8);
    printf("Contas Bancarias em Ordem Alfabética:\n");

    gotoxy(7, 9);
   for (p = L->Primeiro; p != NULL; p = p->proximo) {  // vconfere a lista de exibição
    gotoxy(7, 8);  
    printf("Codigo: %d\n", p->conteudo.codigo);  
    
    gotoxy(7, 10);  
    printf("Banco: %s\n", p->conteudo.Banco);  
    
    gotoxy(7, 11);  
    printf("Agencia: %d\n", p->conteudo.agencia); 
    
    gotoxy(7, 12); 
    printf("Numero da Conta: %d\n", p->conteudo.numConta);
    gotoxy(7, 13);  
    printf("Tipo da Conta: %s\n", p->conteudo.tipo_conta); 
    
    gotoxy(7, 14);  
    printf("Saldo: %.2f\n", p->conteudo.saldo);  
    
    gotoxy(7, 15); 
    printf("Limite: %.2f\n", p->conteudo.Limite);  
    
    gotoxy(7, 16); 
    printf("Status da Conta: %d\n", p->conteudo.statusConta); 
}


    // cabou graças a deus
    gotoxy(7, 23); 
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    getch();

    menucontasbancarias();
}
