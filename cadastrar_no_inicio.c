/*
Autor: Lucas Ulisses - Leonardo Henrique 
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 15/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void cadastrarinicio(){

typedef struct {
    int codigo;
    char Banco[50];
    int agencia;
    int numConta;
    char tipo_conta[50];
    float saldo;
    float Limite;
    int statusConta;
} reg_ContaBanco;

// Estrutura de lista encadeada
typedef struct TipoItem *tipoApontador;

typedef struct TipoItem {
    reg_ContaBanco conteudo;
    tipoApontador proximo;
} TipoItem;

typedef struct {
    tipoApontador Primeiro;
    tipoApontador Ultimo;
} TipoLista;

// Função para inicializar a lista
void InicializarLista(TipoLista *L) {
    L->Primeiro = NULL;
    L->Ultimo = NULL;
}
 reg_funcionarios funcionario;
    tipoApontador p;
    int op;

    do {
        tela();
        telaFuncionarios();
        gotoxy(16, 3);
        printf("Cadastrar Funcionarios");

        gotoxy(16, 7);
        scanf("%d", &funcionario.codigo);

        gotoxy(22, 9);
        fflush(stdin);
        fgets(funcionario.nome, 50, stdin);
        funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

        gotoxy(26, 11);
        fflush(stdin);
        fgets(funcionario.endereco, 50, stdin);
        funcionario.endereco[strcspn(funcionario.endereco, "\n")] = '\0';

        gotoxy(24, 13);
        fflush(stdin);
        fgets(funcionario.cargo, 50, stdin);
        funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';

        gotoxy(35, 15);
        fflush(stdin);
        fgets(funcionario.dt_admissao, 50, stdin);
        funcionario.dt_admissao[strcspn(funcionario.dt_admissao, "\n")] = '\0';

        gotoxy(26, 17);
        fflush(stdin);
        fgets(funcionario.telefone, 50, stdin);
        funcionario.telefone[strcspn(funcionario.telefone, "\n")] = '\0';

        gotoxy(24, 19);
        scanf("%f", &funcionario.salario);

        p = (tipoApontador)malloc(sizeof(TipoItem));
        p->proximo = L->Primeiro;
        p->conteudo = funcionario;
        L->Primeiro = p;

        if (L->Ultimo == NULL) {
            L->Ultimo = p;
        }

        gotoxy(7, 23);
        printf("Deseja cadastrar outro? (1 - Sim / 2 - Nao): ");
        scanf("%d", &op);
    } while (op == 1);
}

// Função para gravar a lista em disco
void GravarListaEmDisco(TipoLista *L) {
    FILE *arquivo = fopen("contas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação!\n");
        return;
    }

    tipoApontador aux = L->Primeiro;
    while (aux != NULL) {
        fwrite(&aux->conteudo, sizeof(reg_ContaBanco), 1, arquivo);
        aux = aux->proximo;
    }

    fclose(arquivo);
    printf("Lista gravada em disco com sucesso!\n");
}

// Função para cadastrar conta no início
void CadastrarContaInicio(TipoLista *L) {
    reg_ContaBanco conta;
    tipoApontador p;

    printf("Digite o código: ");
    scanf("%d", &conta.codigo);

    printf("Digite o nome do banco: ");
    fflush(stdin);
    fgets(conta.Banco, 50, stdin);
    conta.Banco[strcspn(conta.Banco, "\n")] = '\0';

    printf("Digite a agência: ");
    scanf("%d", &conta.agencia);

    printf("Digite o número da conta: ");
    scanf("%d", &conta.numConta);

    printf("Digite o tipo de conta: ");
    fflush(stdin);
    fgets(conta.tipo_conta, 50, stdin);
    conta.tipo_conta[strcspn(conta.tipo_conta, "\n")] = '\0';

    printf("Digite o saldo: ");
    scanf("%f", &conta.saldo);

    printf("Digite o limite: ");
    scanf("%f", &conta.Limite);

    printf("Digite o status da conta (0 - Inativa, 1 - Ativa): ");
    scanf("%d", &conta.statusConta);

    // Aloca memória para o novo nó
    p = (tipoApontador)malloc(sizeof(TipoItem));
    if (p == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }

    // Insere os dados no novo nó
    p->conteudo = conta;
    p->proximo = L->Primeiro;

    // Atualiza o ponteiro da lista
    if (L->Primeiro == NULL) {
        L->Ultimo = p;
    }
    L->Primeiro = p;

    printf("Conta cadastrada no início com sucesso!\n");

    // Grava a lista atualizada em disco
    GravarListaEmDisco(L);
}

// Função para carregar a lista do disco
void CarregarListaDoDisco(TipoLista *L) {
    FILE *arquivo = fopen("contas.bin", "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Iniciando lista vazia.\n");
        return;
    }

    reg_ContaBanco conta;
    while (fread(&conta, sizeof(reg_ContaBanco), 1, arquivo)) {
        tipoApontador p = (tipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            printf("Erro: Memória insuficiente!\n");
            fclose(arquivo);
            return;
        }

        p->conteudo = conta;
        p->proximo = NULL;

        if (L->Primeiro == NULL) {
            L->Primeiro = p;
            L->Ultimo = p;
        } else {
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }
    }

    fclose(arquivo);
    printf("Lista carregada do disco com sucesso!\n");
}

// Função principal
int main() {
    TipoLista lista;
    InicializarLista(&lista);
    CarregarListaDoDisco(&lista);

    int opcao;

    do {
        printf("\nMENU:\n");
        printf("1 - Cadastrar conta no início\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarContaInicio(&lista);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 2);

    return 0;
}