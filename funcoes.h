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
#include <string.h>

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

// Definição do tipo para o ponteiro de estrutura de lista encadeada
typedef struct TipoItem *tipoApontador;
typedef struct TipoItem_conta *tipoApontador_conta;

// Estrutura do nó da lista encadeada
typedef struct TipoItem {
    reg_ContaBanco conteudo;
    tipoApontador proximo;
} TipoItem;

// Estrutura do nó da lista encadeada de contas
typedef struct TipoItem_conta {
    reg_ContaBanco conteudo;
    tipoApontador_conta proximo;
} TipoItem_conta;

// Estrutura da lista de contas
typedef struct {
    tipoApontador Primeiro;
    tipoApontador Ultimo;
} TipoLista;

// Estrutura da lista de contas bancárias com ponteiro tipoApontador_conta
typedef struct {
    tipoApontador_conta Primeiro;
    tipoApontador_conta Ultimo;
} TipoLista_conta;

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

// Remover Funcionarios Inicio
void RemoverFuncionarioFinal(TipoLista *L);

// Cadastrar Na Posição
void CadastrarContaPosicao(TipoLista *L);

// Consultar Contas Por Codigo
void consultarContaCodigo();

// Consultar por nome
void ConsultarOrdemAlfabeticaContas(TipoLista *L);

// Consultar por Ordem de Codigo
void ConsultarOrdemCodigoContas(TipoLista *L);

// Menu de Consultar Contas
void MenuConsultarContas();

// Gravar Contas
void gravar_contas(TipoLista *L);

// Recuperar as Contas
void restaurar_contas(TipoLista *L);

// Listar contas em Geral
void consultaGeralContas(TipoLista *L);

// Função para realizar movimentações de débito e crédito
void movimentacaoDebitoCredito(TipoLista *L);

// Menu Movimentações Bancarias
void desenhar_movimentacao();

// Movimentação de Debito e Credito
void movimentacaoDebitoCredito(TipoLista *L);

#endif
