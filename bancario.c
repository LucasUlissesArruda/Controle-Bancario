#include "Funcoes.h"

// Declaração da lista global
TipoLista lista;

// Função principal
int main() {
    restaurar_contas(&lista);
    
    // Inicialização da lista
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;

    // Desenha a interface inicial
    desenhar_tela();
    telaprincipal();
    getch();

}
