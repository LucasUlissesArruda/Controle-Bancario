/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/
#include "funcoes.h"

// Função para listar todas as contas bancárias cadastradas em ordem alfabética
void ConsultarOrdemAlfabeticaContas(TipoLista *L) {
    system("cls");  
    desenhar_tela();  

    tipoApontador p, q;  
    reg_ContaBanco temp; 
    int contador = 1;  // Contador para exibir a posição das contas

    // Verifica se há alguém na lista
    if (L->Primeiro == NULL) {
        gotoxy(7, 7);  
        printf("Nao existem contas cadastradas."); 
        getch();  
        menucontasbancarias();
        return;
    }

    // Ordena as contas
    for (p = L->Primeiro; p != NULL; p = p->proximo) {  // Olha cada elemento da lista
        for (q = p->proximo; q != NULL; q = q->proximo) {  // Vê os elementos seguintes também
            if (strcmp(p->conteudo.Banco, q->conteudo.Banco) > 0) {  // Compara os nomes
                // Troca os elementos se estiverem fora de ordem
                temp = p->conteudo;
                p->conteudo = q->conteudo;
                q->conteudo = temp;
            }
        }
    }

    // Exibe as contas uma por vez
    tipoApontador atual = L->Primeiro;
    
    while (atual != NULL) {
        system("cls");  // Limpa a tela antes de exibir a próxima conta
        desenhar_tela();  // Redesenha a tela

        gotoxy(7, 3);
        printf("Contas Bancarias em Ordem Alfabética:\n");

        // Exibe os dados da conta
        gotoxy(7, 7);
        printf("Conta %d:", contador);

        gotoxy(7, 8);
        printf("Codigo: %d", atual->conteudo.codigo);

        gotoxy(7, 9);
        printf("Banco: %s", atual->conteudo.Banco);

        gotoxy(7, 10);
        printf("Agencia: %d", atual->conteudo.agencia);

        gotoxy(7, 11);
        printf("Numero da Conta: %d", atual->conteudo.numConta);

        gotoxy(7, 12);
        printf("Tipo da Conta: %s", atual->conteudo.tipo_conta);

        gotoxy(7, 13);
        printf("Saldo: %.2f", atual->conteudo.saldo);

        gotoxy(7, 14);
        printf("Limite: %.2f", atual->conteudo.Limite);

        gotoxy(7, 15);
        printf("Status da Conta: %d", atual->conteudo.statusConta);

        // Aguarda o usuário pressionar uma tecla para ver a próxima conta
        gotoxy(7, 23);
        printf("Pressione qualquer tecla para ver a proxima conta...");
        getch();

        // Move para o próximo nó
        atual = atual->proximo; 
        contador++;
    }

    // Finaliza a exibição
    getch();
    menucontasbancarias();
}
