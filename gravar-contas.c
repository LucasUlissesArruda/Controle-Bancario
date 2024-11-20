#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Funcoes.h"

void gravar_contas(TipoLista *L){
    tipoApontador_conta p;
    reg_ContaBanco reg_ContaBanco;
    FILE *prt;
    char *filename = "Contas.dat";
    char *modo_gravacao = "wb";
    prt = fopen(filename, modo_gravacao);

    desenhar_tela();
    if(prt == NULL){
        printf("Erro ao Abir O Arquivo");
        exit(1);
    }
    else{
        if (L->Primeiro == NULL){
           gotoxy(07,18);
           printf("Lista Vazia. Cadastre Novas Contas");
           getch();
        } else{
            p = L->Primeiro;
            while (p !=NULL){
                reg_ContaBanco = p->conteudo;
                fwrite(&reg_ContaBanco,sizeof(reg_ContaBanco),1,prt);
                p = p->proximo;
            }
        }
        
    }

}