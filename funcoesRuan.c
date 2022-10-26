//GERENCIADOR FINANCEIRO

//serao feitos 12 arquivos, um para cada mes do ano, e cada arquivo tera um registro de cada mes

//serao escrito em binario para facilitar a leitura e escrita,para depois será feito um txt para cada arquivo

//o programa deve ter um menu com as seguintes opcoes:

//0 - Sair

//1 - Cadastrar Saldo

//2 - Cadastrar despesas

//3 - Gerar relatorio

//4 - Forma de pagamento

#include <stdio.h>
#include "funcoes.h"

struct gerenciador_finaceiro gerenciador_financas;

struct gerenciador_finaceiro relatorio_lido;

//funcao que cadastra o saldo e ja cria um funcao que vai criar 12 arquivos com nome:(financas/mes/ano),com o respectivo meses e ano

double cadastrar_saldo() {
    FILE *arquivo;
    //int mes, ano;
    char nome_arquivo[50];
    printf("Digite o nome:");
    scanf("%s", gerenciador_financas.nome);
    printf("Digite o sobrenome:");
    scanf("%s", gerenciador_financas.sobrenome);
    printf("Digite o saldo:");
    scanf("%lf", &gerenciador_financas.saldo);
    printf("Digite o dia:");
    scanf("%d", &gerenciador_financas.dia);
    printf("Digite o mes:");
    scanf("%d", &gerenciador_financas.mes);
    printf("Digite o ano:");
    scanf("%d", &gerenciador_financas.ano);
    sprintf(nome_arquivo, "financas/%d/%d", &gerenciador_financas.mes, &gerenciador_financas.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
    } else {
        fwrite(&gerenciador_financas, sizeof(gerenciador_financas), 1, arquivo);
        fclose(arquivo);
    }
    return gerenciador_financas.saldo;
}

//funcao que cadastra as despesas

void cadastrar_despesas() {
    FILE *arquivo;
    //int mes, ano;
    char nome_arquivo[50];
    printf("Digite a categoria:");
    scanf("%s", gerenciador_financas.categoria);
    printf("Digite a descricao:");
    scanf("%s", gerenciador_financas.descricao);
    printf("Digite o valor:");
    scanf("%lf", &gerenciador_financas.valor);
    printf("Digite o mes:");
    scanf("%d", &gerenciador_financas.mes);
    printf("Digite o ano:");
    scanf("%d", &gerenciador_financas.ano);
    sprintf(nome_arquivo, "financas/%d/%d", &gerenciador_financas.mes, &gerenciador_financas.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
    } else {
        fwrite(&gerenciador_financas, sizeof(gerenciador_financas), 1, arquivo);
        fclose(arquivo);
    }
}

//funcao que gera o relatorio dos gastos nos meses

void gerar_relatorio() {
    FILE *arquivo;
    double total = 0;
    //int mes, ano;
    char nome_arquivo[50];
    printf("Digite o mes:");
    scanf("%d", &gerenciador_financas.mes);
    printf("Digite o ano:");
    scanf("%d", &gerenciador_financas.ano);
    sprintf(nome_arquivo, "financas/%d/%d", &gerenciador_financas.mes, &gerenciador_financas.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
    } else {
        while (fread(&relatorio_lido, sizeof(relatorio_lido), 1, arquivo)) {
            printf("Nome: %s %s", relatorio_lido.nome, relatorio_lido.sobrenome);
            printf("Saldo: %.2f", relatorio_lido.saldo);
            printf("Categoria: %s", relatorio_lido.categoria);
            printf("Descricao: %s", relatorio_lido.descricao);
            printf("Valor: %.2f", relatorio_lido.valor);
            total += relatorio_lido.valor;
        }
        printf("Total a pagar: %.2f", relatorio_lido.saldo - total);
        fclose(arquivo);
    }

    //cria o arquivo txt de cada mes

    FILE *arquivo_txt;
    char nome_arquivo_txt[50];
    sprintf(nome_arquivo_txt, "financas/%d/%d.txt", &gerenciador_financas.mes, &gerenciador_financas.ano);
    printf("nome do arquivo: %s", nome_arquivo_txt);
    arquivo_txt = fopen(nome_arquivo_txt, "a");
    if (arquivo_txt == NULL) {
        printf("Erro ao abrir o arquivo");
    } else {
        fprintf(arquivo_txt, "Nome: %s %s", relatorio_lido.nome, relatorio_lido.sobrenome);
        fprintf(arquivo_txt, "Saldo: %.2f", relatorio_lido.saldo);
        fprintf(arquivo_txt, "Data: %d/%d/%d", relatorio_lido.dia, relatorio_lido.mes, relatorio_lido.ano);
        fprintf(arquivo_txt, "Categoria: %s", relatorio_lido.categoria);
        fprintf(arquivo_txt, "Descricao: %s", relatorio_lido.descricao);
        fprintf(arquivo_txt, "Valor: %.2f", relatorio_lido.valor);
        fprintf(arquivo_txt, "Total a pagar: %.2f", relatorio_lido.saldo - total);
        fclose(arquivo_txt);
    }
}

//menu de opcoes

void menu() {
    int opcao;
    do {
        printf(" 0 - Sair\n");
        printf(" 1 - Cadastrar Saldo\n");
        printf(" 2 - Cadastrar despesas\n");
        printf(" 3 - Gerar relatorio\n");
        printf(" 4 - Forma de pagamento\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...");
                break;
            case 1:
                cadastrar_saldo();
                break;
            case 2:
                cadastrar_despesas();
                break;
            case 3:
                gerar_relatorio();
                break;
            case 4:
                //forma_pagamento();
                break;
            default:
                printf("Opcao invalida");
                break;
        }

    } while (opcao != 0);
}