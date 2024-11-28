#include "funcoes.h"

// Função para validar se a data está no formato correto (dd/mm/aaaa)
int validaData(char *data) {
    int dia, mes, ano;

    // Verifica se a data tem o formato correto (dd/mm/aaaa)
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        return 0;  // Formato inválido
    }

    if (mes < 1 || mes > 12) {
        return 0;  // Mês invalido
    }

    if(dia <1 || dia >=32){
        return 0; // dia invalido
    }

    return 1;  // Formato valido
}
