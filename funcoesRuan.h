//estrutura de dados para armazenar os dados de cada mes do ano

struct gerenciador_finaceiro {
    char *nome;
    char *sobrenome;
    int dia,mes,ano;
    double saldo;
    char *categoria[50];
    char *descricao[50];
    double valor;
    //char forma_pagamento[20];
};

//funcao q chama o menu de opcoes

void menu();

//funcao q cadastra o saldo

void menu();

double cadastrar_saldo();

void cadastrar_despesas();

void gerar_relatorio();