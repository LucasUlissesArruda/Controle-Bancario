/*
Autor: Lucas Ulisses
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
void CadastrarContaPosicao(TipoLista *L, int posicao);

// Remover conta Final
void RemoverContaFinal(TipoLista *L);

// Remover Conta Inicio

void RemoverContaInicio(TipoLista *L);

//Remover conta posição

void RemoverContaPosicao(TipoLista *L);

//Alterar a conta 
void AlterarConta(TipoLista *L);


#endif
