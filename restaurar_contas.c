#include "funcoes.h"

void restaurar_contas(TipoLista *L) {
    reg_ContaBanco reg_ContaBanco;
    FILE *prt;
    char *filename = "Contas.dat";
    char *modo_leitura = "rb";
    prt = fopen(filename, modo_leitura);  // Abre o arquivo em modo leitura binária
    tipoApontador p;
    
    L->Primeiro = NULL;
    L->Ultimo = NULL;
    desenhar_tela();

    if (prt == NULL) {
        gotoxy(07,23);
        printf("O Arquivo ainda nao foi criado. Cadastre as contas Bancarias");
    } else {
        // Lê os dados do arquivo e insere na lista
        while (fread(&reg_ContaBanco, sizeof(reg_ContaBanco), 1, prt) == 1) {
            // Aloca memória para o novo nó
            p = (tipoApontador) malloc(sizeof(TipoItem));
            if (p == NULL) {
                gotoxy(07, 23);
                printf("Erro de memória ao restaurar contas!\n");
                fclose(prt);
                return;
            }

            // Preenche o conteúdo do nó
            p->conteudo = reg_ContaBanco;
            p->proximo = NULL;

            // Se a lista estiver vazia, inicializa com o novo nó
            if (L->Primeiro == NULL) {
                L->Primeiro = p;
                L->Ultimo = p;
            } else {
                // Caso contrário, insere o novo nó no final
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }
        }

        gotoxy(07,23);
        printf("Contas Bancarias Restauradas Com Sucesso");

        fclose(prt);
    }
}
