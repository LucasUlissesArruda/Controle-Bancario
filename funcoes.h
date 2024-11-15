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

//Tipos de Apontadores
void apontadores();

#endif