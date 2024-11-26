#include "Funcoes.h"

// Declaração da lista global
TipoLista lista;

// Função principal
int main() {
    // Inicialização da lista (não é mais necessário inicializar aqui, pois ela é global)
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;

    // Restaura as contas bancárias do arquivo
    restaurar_contas(&lista);

    // Desenha a interface inicial
    desenhar_tela();
    telaprincipal();
    getch();

    return 0;
}
