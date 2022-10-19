//estrutura para armazenarenamento de dados

struct gerenciador_finaceiro {
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

void menu(int opcao);

double receita(struct gerenciador_finaceiro *gerenciadorFinancas);

double despesas(struct gerenciador_finaceiro *gerenciadorFinancas);

void relatorio(struct gerenciador_finaceiro *gerenciadorFinancas, double total);
