#include "funcoes.h"
void restaurar_contas(TipoLista *L) {
    reg_ContaBanco reg_ContaBanco;
    FILE *prt;
    char *filename = "Contas.dat";
    char *modo_leitura = "rb";  
    prt = fopen(filename, modo_leitura);  
    tipoApontador p;

    L->Primeiro = NULL;
    L->Ultimo = NULL;

    desenhar_tela();  

    if (prt == NULL) {
        gotoxy(07, 23);
        printf("O Arquivo ainda nao foi criado. Cadastre as contas Bancarias\n");
        return;
    } else {
        
        while (fread(&reg_ContaBanco, sizeof(reg_ContaBanco), 1, prt) == 1) {
            
            p = (tipoApontador) malloc(sizeof(TipoItem));
            if (p == NULL) {
                gotoxy(07, 23);
                printf("Erro de memória ao restaurar contas!\n");
                fclose(prt);
                return;
            }

            p->conteudo = reg_ContaBanco;
            p->proximo = NULL;

            if (L->Primeiro == NULL) {
                L->Primeiro = p;
                L->Ultimo = p;
            } else {
              
                L->Ultimo->proximo = p;
                L->Ultimo = p;
            }
        }

        gotoxy(07, 23);
        printf("Contas Bancarias Restauradas Com Sucesso\n");

        fclose(prt);  
    }
}
