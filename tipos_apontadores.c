void apontadores(){


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

typedef struct TipoItem *tipoApontador;

typedef struct TipoItem {
    reg_ContaBanco conteudo;
    tipoApontador proximo;
} TipoItem;

typedef struct {
    tipoApontador Primeiro;
    tipoApontador Ultimo;
} TipoLista;
}