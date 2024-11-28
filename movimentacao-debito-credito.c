#include "funcoes.h"

/*
Autor: Lucas Ulisses
RA: Aluno 1: 179114-2024
    Aluno 2: 153939-2023
Data: 25/11/2024
*/

void movimentacaoDebitoCredito(TipoLista *L) {
    int opcao;
    int contaSelecionada;
    reg_ContaBanco conta;
    tipoApontador p;
    Movimentacao movi;
    int codigoFavorecido;
    float valorMovimentacao;
    int resposta;

    desenhar_tela();

    // pede o codigo do individuo
    gotoxy(7, 5);
    printf("Digite o codigo da conta: ");
    scanf("%d", &contaSelecionada);

    // ele procura o individuo na lista de contas bancarias
    p = L->Primeiro;
    while (p != NULL) {
        if (p->conteudo.codigo == contaSelecionada) {
            conta = p->conteudo;
            break;
        }
        p = p->proximo;  // avança para o próximo item na lista
    }

    // não encontrou a conta
    if (p == NULL){
        gotoxy(7, 9);
        printf("Conta nao encontrada");
        getch();
        menumovibancarias();
        return;
    }

    // verifica se a conta dele ta ativa
    if (conta.statusConta == 0) {
        gotoxy(7, 23);
        printf("Conta inativa. Transacao nao permitida");
        getch();
        menumovibancarias();
        return;
    }

    // Mostra as informações da conta
    gotoxy(7, 6);
    printf("Codigo da Conta: %d", conta.codigo);
    gotoxy(7, 7);
    printf("Banco: %s", conta.Banco);
    gotoxy(7, 8);
    printf("Agencia: %d", conta.agencia);
    gotoxy(7, 9);
    printf("Numero da Conta: %d", conta.numConta);
    gotoxy(7, 10);
    printf("Tipo da Conta: %s", conta.tipo_conta);
    gotoxy(7, 11);
    printf("Saldo: %.2f", conta.saldo);
    gotoxy(7, 12);
    printf("Limite: %.2f", conta.Limite);
    gotoxy(7, 13);
    printf("Total Saldo + Limite: %.2f", conta.saldo + conta.Limite);

    // ve se ele tem dinheiro para a transação
    if (conta.saldo + conta.Limite <= 0) {
        gotoxy(7, 23);
        printf("Saldo e limite insuficientes para transacao");
        getch();
        menumovibancarias();
        return;
    }

    // Pede a data da movimentação
    gotoxy(7, 14);
    printf("1-Data Movimentacao dd/mm/aaaa : ");
    fflush(stdin);
    scanf("%s", movi.data);

     // Valida a data
    if (!validaData(movi.data)) {
        gotoxy(7, 23);
        printf("Data invalida. Digite no formato dd/mm/aaaa.");
        getch();
        menumovibancarias();
        return;
    }

    gotoxy(7, 15);
    printf("2-Tipo Movimentacao: ");
    gotoxy(7, 16);
    printf("1 - Debito    2 - Credito:");
    scanf("%d", &opcao);

    // verifica se vc digitou certo
    if (opcao != 1 && opcao != 2) {
        gotoxy(7, 23);
        printf("Opcao invalida para tipo de movimentacao");
        getch();
        menumovibancarias();
        return;
    }

    // Pede o codigo do queridao
    gotoxy(7, 17);
    printf("3-Favorecido: ");
    scanf("%d", &codigoFavorecido);

    if(contaSelecionada  == codigoFavorecido){
        gotoxy(7,23);
        printf("Nao pode mandar para a mesma conta");
        getch();
        menumovibancarias();
    }

    // Pede o valor da movimentação
    gotoxy(7, 18);
    printf("4-Valor Movimentacao: ");
    scanf("%f", &valorMovimentacao);

    // ve se o valor é maior que 0
    if (valorMovimentacao <= 0) {
        gotoxy(7, 23);
        printf("Valor de movimentacao invalido");
        getch();
        menumovibancarias();
        return;
    }

    // começa a movimentação
    if (opcao == 1) {  // Débito
        if (conta.saldo > 0) {
            // retira o valor do saldo da conta
            conta.saldo = conta.saldo - valorMovimentacao;
        } else if (conta.saldo == 0) {
            // Se o saldo for 0, usa o limite
            if (conta.Limite >= valorMovimentacao) {
                conta.Limite = conta.Limite - valorMovimentacao;
            } else {
                gotoxy(7, 23);
                printf("Limite insuficiente");
                getch();
                menumovibancarias();
                return;
            }
        } else {
            // se não tiver nada na conta
            gotoxy(7, 23);
            printf("Saldo insuficiente");
            gotoxy(7, 24);
            printf("Saldo atual: %.2f", conta.saldo);
            getch();
            menumovibancarias();
            return;
        }

        // Encontra o favorecido e adiciona o valor
        tipoApontador pFavorecido = L->Primeiro;
        while (pFavorecido != NULL) {
            if (pFavorecido->conteudo.codigo == codigoFavorecido) {
                pFavorecido->conteudo.saldo = pFavorecido->conteudo.saldo + valorMovimentacao; //manda o valor na conta do favorecido
                break;
            }
            pFavorecido = pFavorecido->proximo;  // Avança para o próximo item na lista
        }
        if (pFavorecido == NULL) {
            gotoxy(7, 23);
            printf("Favorecido nao encontrado");
            conta.saldo =  conta.saldo + valorMovimentacao;  // Não achou o favorecido, devolve o valor
            conta.Limite = conta.Limite + valorMovimentacao;
            getch();
            movimentacaoDebitoCredito(L); 
            return;
        }

    } else if (opcao == 2) {  // Crédito
        conta.saldo = conta.saldo - valorMovimentacao;  // retira o valor do saldo da conta

        // Encontra o favorecido e adiciona o valor
        tipoApontador pFavorecido = L->Primeiro;
        while (pFavorecido != NULL) {
            if (pFavorecido->conteudo.codigo == codigoFavorecido) {
                pFavorecido->conteudo.saldo = pFavorecido->conteudo.saldo + valorMovimentacao;  // manda o valor para conta do favorecido
                break;
            }
            pFavorecido = pFavorecido->proximo;  // Avança para o próximo item na lista
        }
        if (pFavorecido == NULL) {
            gotoxy(7, 23);
            printf("Favorecido nao encontrado");
            getch();
            menumovibancarias();
            return;
        }
    }

    // Exibe o novo saldo da conta
    gotoxy(7, 19);
    printf("5-Novo Saldo: %.2f", conta.saldo);
    gotoxy(7, 20);
    printf("6-Novo Limite: %.2f", conta.Limite);

    gotoxy(7,23);
    printf("Transacao efetuada com sucesso");
    getch();

    // Pergunta se deseja gravar as informações
    
    gotoxy(7, 23);
    printf("Deseja gravar a transacao? (1 - Sim / 2 - Nao): ");
    fflush(stdin);
    scanf("%d", &resposta);

    if (resposta == 1) {
    // Atualiza os saldos na lista
        p->conteudo = conta;  // Atualiza os dados da conta na lista
        gravar_movi(L);  
    }

    menumovibancarias();  
}
