#include "funcoes.h"

void restaurar_contas(TipoLista *L) {
    reg_ContaBanco reg_ContaBanco;
    FILE *prt;
    char *filename = "Contas.dat";
    char *modo_leitura = "rb";
    tipoApontador p;

    system("cls");  // Limpa a tela
    desenhar_tela();  // Desenha a interface gráfica

    L->Primeiro = NULL;
    L->Ultimo = NULL;

    prt = fopen(filename, modo_leitura);

    if (prt == NULL) {
        gotoxy(7, 23);
        printf("O arquivo ainda nao foi criado. Cadastre as contas bancarias.");
        return;
    }

    while (fread(&reg_ContaBanco, sizeof(reg_ContaBanco), 1, prt) == 1) {
        p = (tipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Erro de memoria ao restaurar contas!");
            fclose(prt);
            return;
        }

        p->conteudo = reg_ContaBanco;
        p->proximo = NULL;

        if (L->Primeiro == NULL) {  // Se for o primeiro elemento
            L->Primeiro = p;
            L->Ultimo = p;
        } else {  // Adiciona no final da lista
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }
    }

    fclose(prt);

    gotoxy(7, 23);
    printf("Contas bancarias restauradas com sucesso!");
    getch();  // Pausa para exibir a mensagem
}
