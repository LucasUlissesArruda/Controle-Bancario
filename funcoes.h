/*
Autor: Lucas Ulisses - Leonardo Henrique
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// Definições globais de tipos
typedef struct {
    int codigo;
    char Banco[50];
    int agencia;
    int numConta;
    char tipo_conta[50];
    float saldo;
    float Limite;
    int statusConta;
    char ultimaDataMovimentacao[11];
} reg_ContaBanco;

typedef struct TipoItem *tipoApontador;

typedef struct TipoItem {
    reg_ContaBanco conteudo;
    tipoApontador proximo;
} TipoItem;

typedef struct {
    tipoApontador Primeiro;
    tipoApontador Ultimo;
} TipoLista;

// Estrutura da lista de contas bancárias com ponteiro tipoApontador_conta
typedef struct {
    tipoApontador Primeiro;
    tipoApontador Ultimo;
} TipoLista_conta;

typedef struct {
    char data[11];
    char favorecido[50];
    char tipoMov[10]; // Débito ou Crédito
    float valor;
    float saldo;
} Movimentacao;

// Compartilhar a lista global entre os arquivos
extern TipoLista lista;
extern TipoLista_conta lista_contas;

// Desenha a tela padrao
void desenhar_tela();

// Posiciona o cursor na Tela
void gotoxy(int x, int y);

// Muda a cor da tela.
void mudar_cor(int cor);

// Exibir a Primeira tela
void telaprincipal();

// Exibe o menu de contas bancarias
void menucontasbancarias();

// Exibe o menu de Movimentações Bancarias
void menumovibancarias();

// Cadastra conta do final 
void CadastrarContaFinal(TipoLista *L);

// Cadastra conta no inicio
void CadastrarContaInicio(TipoLista *L);

// Cadastrar na posição
void CadastrarContaPosicao(TipoLista *L);

// Remover conta Final
void RemoverContaFinal(TipoLista *L);

// Remover Conta Inicio

void RemoverContaInicio(TipoLista *L);

//Remover conta posição

void RemoverContaPosicao(TipoLista *L);

//Alterar a conta 
void AlterarConta(TipoLista *L);


// Transereir Entre contas Bancarias
void TransferirEntreContas(TipoLista *L);

// gravar as movimentações
void gravar_movi(TipoLista *L);

// carregar as movimentacoes
void restaurar_Movi(TipoLista *L);

// validar data
int validaData(char *data);

// menu de remover
void MenuRemover();

#endif
