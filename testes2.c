#include <stdio.h>
//#include <stdlib.h>

//gerenciadoir financeiro

//estrutura para armazenar as infomações de cada gasto

typedef struct{
    char categoria[50];
    char descricao[50];
    float valor;
    int dia,mes,ano;
}gerenciador_fincanceiro;

//funcao para cadastrar a receita

void receita(){
    float saldo;
    printf("Digite o saldo inicial: ");
    scanf("%f", &saldo);
    printf("Saldo cadastrado com sucesso!\n");
}

//funcao para cadastrar as despesas

void despesa(){
    gerenciador_fincanceiro g;
    printf("Digite a categoria: ");
    scanf("%s", g.categoria);
    printf("Digite a descricao: ");
    scanf("%s", g.descricao);
    printf("Digite o valor: ");
    scanf("%f", &g.valor);
    printf("Digite o dia: ");
    scanf("%d", &g.dia);
    printf("Digite o mes: ");
    scanf("%d", &g.mes);
    printf("Digite o ano: ");
    scanf("%d", &g.ano);
    printf("Despesa cadastrada com sucesso!\n");
}

//funcao para gerar um arquivo binario com as com a reiceita e as despesas

void gerar_arquivo(){
    FILE *arq = fopen("arquivo.bin", "wb");
    gerenciador_fincanceiro g;
    printf("Digite a categoria: ");
    scanf("%s", g.categoria);
    printf("Digite a descricao: ");
    scanf("%s", g.descricao);
    printf("Digite o valor: ");
    scanf("%f", &g.valor);
    printf("Digite o dia: ");
    scanf("%d", &g.dia);
    printf("Digite o mes: ");
    scanf("%d", &g.mes);
    printf("Digite o ano: ");
    scanf("%d", &g.ano);

    fwrite(&g, sizeof(gerenciador_fincanceiro), 1, arq);
    fclose(arq);
    printf("Arquivo gerado com sucesso!\n");
}

//funcao para ler o arquivo binario

void ler_arquivo() {
    FILE *arq2 = fopen("arquivo.bin", "rb");
    gerenciador_fincanceiro g;
    fread(&g, sizeof(gerenciador_fincanceiro), 1, arq2);
    fclose(arq2);
    printf("Categoria: %s", g.categoria);
    printf("Descricao: %s", g.descricao);
    printf("Valor: %.2f", g.valor);
    printf("Data: %d/%d/%d", g.dia, g.mes, g.ano);
}

//funcao para gerar um arquivo txt com as com a reiceita e as despesas

void gerar_txt() {
    FILE *arq3 = fopen("arquivo.txt", "a");
    gerenciador_fincanceiro g;
    fprintf(arq3, "Categoria: %s", g.categoria);
    fprintf(arq3, "Descricao: %s", g.descricao);
    fprintf(arq3, "Valor: %.2f", g.valor);
    fprintf(arq3, "Data: %d/%d/%d", g.dia, g.mes, g.ano);
    fclose(arq3);
}

//funcao para ler o arquivo txt

void ler_txt() {
    FILE *arq4 = fopen("arquivo.txt", "r");
    gerenciador_fincanceiro g;
    fscanf(arq4, "Categoria: %s", g.categoria);
    fscanf(arq4, "Descricao: %s", g.descricao);
    fscanf(arq4, "Valor: %.2f", &g.valor);
    fscanf(arq4, "Data: %d/%d/%d", &g.dia, &g.mes, &g.ano);
    fclose(arq4);
}

//funcao para gerar relatorio de despesas do ultimo mes

void relatorio_despesas_ultimoMes() {
    FILE *arq5 = fopen("arquivo.bin", "rb");
    gerenciador_fincanceiro g;
    fread(&g, sizeof(gerenciador_fincanceiro), 1, arq5);
    fclose(arq5);
    printf("Categoria: %s", g.categoria);
    printf("Descricao: %s", g.descricao);
    printf("Valor: %.2f", g.valor);
    printf("Data: %d/%d/%d", g.dia, g.mes, g.ano);
}

//funcao formas de pagamento

void formas_pagamento() {
    int opcao;
    printf("1 - Dinheiro\n");
    printf("2 - Cartao de credito\n");
    printf("3 - Cartao de debito\n");
    printf("4 - Cheque\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    switch(opcao) {
        case 1:
            printf("Dinheiro\n");
            break;
        case 2:
            printf("Cartao de credito\n");
            break;
        case 3:
            printf("Cartao de debito\n");
            break;
        case 4:
            printf("Cheque\n");
            break;
        default:
            printf("Opcao invalida\n");
    }
}

//funcao para pagamento em dinheiro



//funcao do menu

void menu() {
    int opcao;
    do{
         printf("----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar Saldo\n");
    printf("2 - Cadastrar despesas\n");
    printf("3 - Gerar relatorio do ultimo mes\n");
    printf("4 - Gerar relatorio dos ultimos 12 meses\n");
    printf("5 - Forma de pagamento\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) 
        {
        case 0:
            printf("Saindo do programa...\n");
            break;
        case 1:
            printf("\033c");
            printf("Cadastrar Saldo\n");
            receita();
            break;
        case 2:
        // ** POR ALGUM MOTIVO AO DIGITAR AS DESPESAS ELE ESTÁ PERGUNTANDO 2 VEZES AUTOMATICAMENTE
        // PODEMOS FAZER UMA OPÇÃO NESSA FUNÇÃO COLOCANDO QUANTAS DESPESAS SERÃO CADASTRADAS!!
            printf("Cadastrar despesas\n");
            despesa();
            gerar_arquivo();
            ler_arquivo();
            gerar_txt();
            break;
        case 3:
            printf("Gerar relatorio do ultimo mes\n");
            ler_txt();
            relatorio_despesas_ultimoMes();
            break;
        case 4:
            printf("Gerar relatorio dos ultimos 12 meses\n");
            break;
        case 5:
            printf("Forma de pagamento\n");
            formas_pagamento();
            break;
        default:
            printf("\033c");
            printf("Opção inválida!\n");
            return menu();
    
    } 
    }
    while (opcao != 0);
        printf("----------------------------------------------------------\n");

}
    int main() {
        menu();
    }

