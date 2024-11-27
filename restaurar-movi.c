#include "funcoes.h"

void restaurar_Movi(TipoLista *L) {
    reg_ContaBanco reg_ContaBanco;
    FILE *prt;
    char *filename = "Movimentacao.dat";
    char *modo_leitura = "rb";
    tipoApontador p;

    system("cls"); 
    desenhar_tela(); 

    L->Primeiro = NULL;
    L->Ultimo = NULL;

    prt = fopen(filename, modo_leitura);

    if (prt == NULL) {
        gotoxy(7, 23);
        printf("O arquivo ainda nao foi criado. Cadastre as movimentacoes bancarias.");
        return;
    }

    while (fread(&reg_ContaBanco, sizeof(reg_ContaBanco), 1, prt) == 1) {
        p = (tipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Erro de memoria ao restaurar movimentacoes!");
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

    fclose(prt);

    gotoxy(7, 23);
    printf("movimentacoes bancarias restauradas com sucesso!");
    getch();  
}
