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
    // Inicializa a lista antes de restaurar as contas
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;

    // Restaura as contas do arquivo para a lista
    restaurar_contas(&lista);

    desenhar_tela();
    telaprincipal();
    getch();

    return 0;
}
