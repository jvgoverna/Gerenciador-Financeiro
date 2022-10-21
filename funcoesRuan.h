//estrutura para armazenarenamento de dados

struct gerenciador_finaceiro{
    char *nome[50];
    char *sobrenome[50];
    double saldo;
    char *categoria[50];
    char *descricao[50];
    double valor;
    int dia,mes,ano;
    //char *formaPagamento[50];
    //double valorPago;
};

void menu();

void mes_anterior(int ano,int mes,int *ano_a,int *mes_a);

double receita();

double despesas();

void relatorio(double total);
