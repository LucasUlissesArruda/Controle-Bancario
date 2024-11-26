#include "Funcoes.h"
#include <conio.h>

// Função para remover a última conta cadastrada na lista
void RemoverContaFinal(TipoLista *L) {
    tipoApontador p, temp;  // ponteiro para a lista temporario
    int confirmacao;  

    system("cls");  
    desenhar_tela();  

    // Verifica se a lista de contas está vazia
    if (L->Primeiro == NULL) {
        gotoxy(7, 12);  
        printf("Nenhuma conta cadastrada!");  // mostra que não tem contas
        getch();  
        return; 
    }

    temp = L->Ultimo;  // Aponta para a última conta da lista

    // Mostra as informações se der certo
    gotoxy(7, 7);
    printf("Ultima conta cadastrada:");
    gotoxy(7, 8);
    printf("Codigo: %d", temp->conteudo.codigo);
    gotoxy(7, 9);
    printf("Banco: %s", temp->conteudo.Banco);
    gotoxy(7, 10);
    printf("Agencia: %d", temp->conteudo.agencia);
    gotoxy(7, 11);
    printf("Numero da Conta: %d", temp->conteudo.numConta);
    gotoxy(7, 12);
    printf("Tipo de Conta: %s", temp->conteudo.tipo_conta);
    gotoxy(7, 13);
    printf("Saldo: R$ %.2f", temp->conteudo.saldo);
    gotoxy(7, 14);
    printf("Limite: R$ %.2f", temp->conteudo.Limite);
    gotoxy(7, 15);
    printf("Status: %d", temp->conteudo.statusConta);

    // Solicita confirmação do usuário para remover a conta
    gotoxy(7, 17);
    printf("Deseja remover esta conta? (1 - Sim / 2 - Não): ");
    scanf("%d", &confirmacao);

    // se não for 1 ele cancela 
    if (confirmacao != 1) {
        gotoxy(7, 19);
        printf("Operacao cancelada.");  
        getch();  
        return;  
    }

    // se tiver so um, ele remove apenas ele
    if (L->Primeiro == L->Ultimo) {
        free(L->Primeiro);  // fuma a memória da última conta
        L->Primeiro = NULL;  // ele deixa a lista como NULL
        L->Ultimo = NULL;  // ele deixa a lista como NULL
    } else {
        // se tiver outro, ele vai ate o penultimo
        p = L->Primeiro;
        while (p->proximo != L->Ultimo) {  // Vai ate  o penúltimo elemento
            p = p->proximo;  // Move o ponteiro para o próximo
        }
        free(L->Ultimo);  // Fuma a memória da última conta
        L->Ultimo = p;  // O penúltimo elemento agora é o último
        L->Ultimo->proximo = NULL;  
    }

    // Fala que removeu
    gotoxy(7, 19);
    printf("Conta removida com sucesso!");
    
    gravar_contas(L);  // Grava a lista atualizada no arquivo
    getch();  
    menucontasbancarias(); 
}
