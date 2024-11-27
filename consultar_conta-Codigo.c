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

    atual = L->Primeiro;  // Inicializa o ponteiro com o primeiro elemento
    
    // Percorre a lista procurando o codigo
    while (atual != NULL) {
        if (atual->conteudo.codigo == numeroBusca) {  // Verifica se o codigo existe
            gotoxy(9, 7); 
            printf("\nConta encontrada:\n"); 
            
            // Mostra as informações
            gotoxy(7, 10);
            printf("Codigo: %d\n", atual->conteudo.codigo);
            gotoxy(7, 11);
            printf("Banco: %s\n", atual->conteudo.Banco);
            gotoxy(7, 12);
            printf("Agencia: %d\n", atual->conteudo.agencia);
            gotoxy(7, 13);
            printf("Numero da Conta: %d\n", atual->conteudo.numConta);
            gotoxy(7, 14);
            printf("Tipo da Conta: %s\n", atual->conteudo.tipo_conta);
            gotoxy(7, 15);
            printf("Saldo: %.2f\n", atual->conteudo.saldo);
            gotoxy(7, 16);
            printf("Limite: %.2f\n", atual->conteudo.Limite);
            gotoxy(7, 17);
            printf("Status da Conta: %d\n", atual->conteudo.statusConta);
            
            encontrado = 1;  // Atualiza a flag indicando que a conta foi encontrada.
            break; 
        }
        atual = atual->proximo;  // Ponteiro vai para o proximo da lista
    }

    // Se não achar o codigo ele apresenta uma mensagem
    if (!encontrado) {
        gotoxy(7, 23); 
        printf("\nConta com numero %d nao encontrada.\n", numeroBusca);  // Mostra o erro
        getch();  
        MenuConsultarContas();  
    } else {
        // Pergunta se ele quer fazer uma nova pesquisa
        gotoxy(7, 23);  
        printf("Deseja fazer uma nova consulta? 1-Sim 2-Nao: "); // Pergunta se ele quer continuar
        scanf("%d", &opc); 

        
        if (opc == 1) {
            consultarContaCodigo(L);  // Consulta dnv
        } else {
            MenuConsultarContas();  // Volta para o menu
        }
    }
}
