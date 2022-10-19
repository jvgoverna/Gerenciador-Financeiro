//estrutura para armazenarenamento de dados

struct gerenciador_finaceiro {
    char *nome[50];
    char *sobrenome[50];
    double saldo;
    char *categoria[50];
    char *descricao[50];
    double valor;
    int dia,mes,ano;
    char *formaPagamento[50];
    double valorPago;
};

struct gerenciador_finaceiro gerenciador_financas;

struct gerenciador_finaceiro relatorio_lido;

void menu();

double receita(struct gerenciador_finaceiro *gerenciador_financas);

double despesas(struct gerenciador_finaceiro *gerenciador_financas);

void relatorio(struct gerenciador_finaceiro *gerenciador_financas, double total);
