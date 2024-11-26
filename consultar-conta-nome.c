#include "funcoes.h"

void ConsultarOrdemAlfabeticaContas(TipoLista *L) {
    system("cls");  
    desenhar_tela();  

    tipoApontador p, q;  // Ponteiros para percorrer a lista
    reg_ContaBanco temp; // Variável temporária para troca durante a ordenação

    // Verifica se a lista está vazia
    if (L->Primeiro == NULL) {
        gotoxy(7, 7);  
        printf("Nao existem contas cadastradas.\n"); 
        getch();  
        return;
    }

    // Ordenação da lista em ordem alfabética pelo nome do banco
    for (p = L->Primeiro; p != NULL; p = p->proximo) {  // Itera sobre cada elemento da lista
        for (q = p->proximo; q != NULL; q = q->proximo) {  // Itera sobre os elementos seguintes
            if (strcmp(p->conteudo.Banco, q->conteudo.Banco) > 0) {  // Compara os nomes dos bancos
                // Troca os conteúdos das posições se estiverem fora de ordem
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    // Exibição das contas em ordem alfabética
    gotoxy(7, 7);
    printf("Contas Bancarias em Ordem Alfabética:\n");

    gotoxy(7, 7);
   for (p = L->Primeiro; p != NULL; p = p->proximo) {  // Percorre a lista para exibição
    gotoxy(7, 8);  
    printf("Codigo: %d\n", p->conteudo.codigo);  // Exibe o código da conta
    
    gotoxy(7, 9);  
    printf("Banco: %s\n", p->conteudo.Banco);  // Exibe o nome do banco
    
    gotoxy(7, 10);  // Atualiza a posição do cursor
    printf("Agencia: %d\n", p->conteudo.agencia);  // Exibe o número da agência
    
    gotoxy(7, 11); 
    printf("Numero da Conta: %d\n", p->conteudo.numConta);  // Exibe o número da conta
    
    gotoxy(7, 12);  
    printf("Tipo da Conta: %s\n", p->conteudo.tipo_conta);  // Exibe o tipo da conta
    
    gotoxy(7, 13);  
    printf("Saldo: %.2f\n", p->conteudo.saldo);  // Exibe o saldo da conta
    
    gotoxy(7, 14); 
    printf("Limite: %.2f\n", p->conteudo.Limite);  // Exibe o limite da conta
    
    gotoxy(7, 15);  // Atualiza a posição do cursor
    printf("Status da Conta: %d\n", p->conteudo.statusConta);  // Exibe o status da conta (ativa/inativa)
}


    // Finalização
    gotoxy(7, 23); 
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    getch();

    menucontasbancarias();
}
