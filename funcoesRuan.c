#include <stdio.h>
#include "funcoesRuan.h"

void menu(int opcao) {
    printf("Menu de opções:");
    printf("1 - Cadastrar Saldo");
    printf("2 - Cadastrar despesas");
    printf("3 - Gerar relatório");
    printf("4 - Forma de pagamento");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            receita(gerenciadorFinancas)
            break;
        case 2:
            despesas(gereciadorFinancas,total);
            break;
        case 3:
            relatorio(gereciadorFinancas,total);
            break;
        case 4:
            printf("Forma de pagamento: ");
            scanf("%s", gereciadorFinancas->formaPagamento);
            printf("Valor pago: ");
            scanf("%lf", &gereciadorFinancas->valorPago);
            printf("Troco: %lf", gereciadorFinancas->valorPago - total);
            break;
        default:
            printf("Opção inválida!");
            break;
    }

}

double receita(struct gerenciador_finaceiro *gerenciadorFinancas){
    printf("Digite o saldo atual: ");
    scanf("%lf", gerenciadorFinancas->saldo);

    return gerenciadorFinancas->saldo;
}

double despesas(struct gerenciador_finaceiro *gerenciadorFinancas){
    double total = 0;
    printf("Digite a categoria: ");
    scanf("%s", gerenciadorFinancas->categoria);
    printf("Digite a descrição: ");
    scanf("%s", gerenciadorFinancas->descricao);
    printf("Digite o valor: ");
    scanf("%lf", &gerenciadorFinancas->valor);
    printf("Digite o dia: ");
    scanf("%d", &gerenciadorFinancas->dia);
    printf("Digite o mês: ");
    scanf("%d", &gerenciadorFinancas->mes);
    printf("Digite o ano: ");
    scanf("%d", &gerenciadorFinancas->ano);

    total += gerenciadorFinancas->valor;

    FILE *f = fopen("despesas.bin", "wb");

    fwrite(&gerenciadorFinancas, sizeof(struct gerenciador_finaceiro), 1, f);

    fclose(f);

    return total;
}

void relatorio( struct gerenciador_finaceiro *gerenciadorFinancas, double total){

    FILE *fr = fopen("despesas.bin", "rb");

    fread(&relatorio_lido, sizeof(struct gerenciador_finaceiro), 1, fr);

    fclose(fr);

    printf("Categoria: %s\n", gerenciadorFinancas->categoria);
    printf("Descrição: %s\n", gerenciadorFinancas->descricao);
    printf("Valor: %lf\n", gerenciadorFinancas->valor);
    printf("Data: %d/%d/%d\n", gerenciadorFinancas->dia, gerenciadorFinancas->mes, gerenciadorFinancas->ano);
    printf("Total: %lf\n", total);

    FILE *ftxt = fopen("relatorio.txt", "a");

    fprintf(ftxt, "Categoria: %s\n", gerenciadorFinancas->categoria);
    fprintf(ftxt, "Descrição: %s\n", gerenciadorFinancas->descricao);
    fprintf(ftxt, "Valor: %lf\n", gerenciadorFinancas->valor);
    printf("Data: %d/%d/%d\n", gerenciadorFinancas->dia, gerenciadorFinancas->mes, gerenciadorFinancas->ano);

    fclose(ftxt);
}

