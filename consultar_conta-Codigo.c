/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 22/11/2024
*/
#include <stdio.h>
#include "Funcoes.h"

// Função para consultar uma conta bancária pelo código informado pelo usuário
void consultarContaCodigo(TipoLista *L) {
    system("cls"); 
    desenhar_tela(); 

    int opc;
    int numeroBusca;  
    tipoApontador atual; 
    int encontrado = 0; 

    // se a lista estiver vazia, mostra isso ae
    if (L->Primeiro == NULL) {
        gotoxy(7, 23); 
        printf("Nenhuma conta cadastrada!\n"); 
        getch();  
        menucontasbancarias(); 
        return; 
    }
    
    gotoxy(7, 7); 
    printf("Digite o Codigo da conta que deseja consultar: "); 
    scanf("%d", &numeroBusca);  // le o codigo que você colocou

    atual = L->Primeiro;  // começa a lista com o primeiro elemento
    
    // corre a lista procurando seu codigo
    while (atual != NULL) {
        if (atual->conteudo.codigo == numeroBusca) {  // Verifica se o codigo existe
            gotoxy(9, 7); 
            printf("Conta encontrada:"); 
            
            // Mostra as informações
            gotoxy(7, 10);
            printf("Codigo: %d", atual->conteudo.codigo);
            gotoxy(7, 11);
            printf("Banco: %s", atual->conteudo.Banco);
            gotoxy(7, 12);
            printf("Agencia: %d", atual->conteudo.agencia);
            gotoxy(7, 13);
            printf("Numero da Conta: %d", atual->conteudo.numConta);
            gotoxy(7, 14);
            printf("Tipo da Conta: %s", atual->conteudo.tipo_conta);
            gotoxy(7, 15);
            printf("Saldo: %.2f", atual->conteudo.saldo);
            gotoxy(7, 16);
            printf("Limite: %.2f", atual->conteudo.Limite);
            gotoxy(7, 17);
            printf("Status da Conta: %d", atual->conteudo.statusConta);
            
            encontrado = 1;  // opa, encontrou
            break; 
        }
        atual = atual->proximo;  // pula para o proximo
    }

    // se não achar da nisso dae
    if (!encontrado) {
        gotoxy(7, 23); 
        printf("\nConta com numero %d nao encontrada.", numeroBusca); 
        getch();  
        MenuConsultarContas();  
    } else {
        // quer ir dnv ?
        gotoxy(7, 23);  
        printf("Quer fazer uma nova consulta? 1-Sim 2-Nao: ");
        scanf("%d", &opc); 

        
        if (opc == 1) {
            consultarContaCodigo(L);  // Consulta dnv
        } else {
            MenuConsultarContas();  // Volta para o menu
        }
    }
}
