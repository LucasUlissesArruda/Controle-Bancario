/*
Autor: Lucas Ulisses - Leonardo Henrique 
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include "funcoes.h"
#include <stdio.h>

TipoLista lista;

int main() {
    restaurar_contas(&lista);
    
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;

    desenhar_tela();
    telaprincipal();
    getch();

}