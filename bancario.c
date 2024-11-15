/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/
#include "Funcoes.h"

// Declarar a lista globalmente
TipoLista lista;

int main() {
    // Inicializar a lista
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;

    desenhar_tela();
    telaprincipal();

    getch();
    return 0;
}
