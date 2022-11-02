#include <stdio.h>

typedef struct{
    char descricao[30];
    char categoria[30];
    double valor;
    int dia,mes,ano;
}gerenciador;
void desc(void *d){ //Funcao utilizada para receber varias strings do usuario
    scanf(" %99[^\n]", d);
}
void cadastrar(){
    gerenciador g;
    printf("Digite a categoria: \n");
    scanf("%s",g.categoria);
    printf("Digite a descrição: \n");
    scanf("%s",g.descricao);
    printf("Digite o valor: \n");
    scanf("%lf",&g.valor);
    printf("Digite o dia: \n");
    scanf("%d",&g.dia);
    printf("Digite o mês: \n");
    scanf("%d",&g.mes);
    printf("Digite o ano: \n");
    scanf("%d",&g.ano);
}

void arquivo_binário(){
    gerenciador g;
    FILE *arquivo;
    char nome_arquivo[50];
    printf("\n");
    printf("Digite a categoria desejada:\n");
    scanf("%s",g.categoria);
    printf("Digite o mes desejado:\n");
    scanf("%d", &g.mes);
    printf("Digite o ano desejado:\n");
    scanf("%d", &g.ano);
    sprintf(nome_arquivo, "financas/%04d%02d", g.ano, g.mes); //criar pasta financas para rodar o programa
    printf("\nnome do arquivo: %s\n", nome_arquivo);
    arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        fwrite(&g, sizeof(gerenciador), 1, arquivo);
        printf("\nArquivo gravado com sucesso\n");
    }
    fclose(arquivo);

}

void relatorioPorCat(){
    gerenciador g;
    FILE *arquivo2;
    char nome_arquivo[50];
    sprintf(nome_arquivo, "financas/%s%04d%02d", g.categoria,g.ano, g.mes);
    printf("\nnome do arquivo: %s\n", nome_arquivo);
    arquivo2 = fopen(nome_arquivo, "wb");
    if (arquivo2 == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        fwrite(&g, sizeof(gerenciador), 1, arquivo2);
        printf("\nArquivo gravado com sucesso\n");
    }
    fclose(arquivo2);
}

void relatorio_ultimoMes(){ //nao ta printando todos as despesas do mes
    gerenciador g;
    printf("Digite a categoria novamente:\n");
    desc(&g.categoria);
    printf("Digite o mes novamente:\n");
    scanf("%d", &g.mes);
    printf("Digite o ano navamente:\n");
    scanf("%d", &g.ano);
    FILE *arquivo2;
    char nome_arquivo[50];
    sprintf(nome_arquivo, "financas/%s%04d%02d", g.categoria,g.ano, g.mes);
    printf("\nnome do arquivo: %s\n", nome_arquivo);
    arquivo2 = fopen(nome_arquivo, "rb");
    if (arquivo2 == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        while (fread(&g, sizeof(g), 1, arquivo2)) {
            printf("\nData: %02d/%02d/%04d\n", g.dia, g.mes, g.ano);
            printf("Categoria: %s\n", g.categoria);
            printf("Descricao: %s\n", g.descricao);
            printf("Valor: %.2f\n", g.valor);
        }
        printf("\nArquivo lido com sucesso\n");
    }
    fclose(arquivo2);
}

void relatorio_12meses(){
    gerenciador g;
    printf("Digite o mes novamente:\n");
    scanf("%d", &g.mes);
    printf("Digite o ano navamente:\n");
    scanf("%d", &g.ano);
    FILE *arquivo;
    char nome_arquivo[50];
    for (g.mes = 01; g.mes <= 12; g.mes++) {
        sprintf(nome_arquivo, "financas/%04d%02d", g.ano, g.mes);
        printf("\nnome do arquivo: %s\n", nome_arquivo);
        arquivo = fopen(nome_arquivo, "rb");
        if (arquivo == NULL) {
            printf("\nErro ao abrir o arquivo\n");
        } else {
            while (fread(&g, sizeof(g), 1, arquivo)) {
                //printf("Saldo: %.2f", g.saldo);
                printf("\nData: %02d/%02d/%04d\n", g.dia, g.mes, g.ano);
                printf("Categoria: %s\n", g.categoria);
                printf("Descricao: %s\n", g.descricao);
                printf("Valor: %.2f\n", g.valor);
                //total += relatorio_lido.valor;
            }
            //printf("Total a pagar: %.2f", g.saldo - total);
            printf("\nArquivo lido com sucesso\n");
        }
        fclose(arquivo);
    }
}

void passar_txt() {
    gerenciador g;
    FILE *arquivo_txt;
    char nome_arquivo_txt[50];
    sprintf(nome_arquivo_txt, "financas/%04d%02d.txt", g.ano, g.mes);
    printf("\nnome do arquivo: %s\n", nome_arquivo_txt);
    arquivo_txt = fopen(nome_arquivo_txt, "a");
    if (arquivo_txt == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        //fprintf(arquivo_txt, "Saldo: %.2f", g.saldo);
        fprintf(arquivo_txt, "\nData: %02d/%02d/%04d\n", g.dia, g.mes, g.ano);
        fprintf(arquivo_txt, "Categoria: %s\n", g.categoria);
        fprintf(arquivo_txt, "Descricao: %s\n", g.descricao);
        fprintf(arquivo_txt, "Valor: %.2f\n", g.valor);
        //fprintf(arquivo_txt, "Total a pagar: %.2f", g.saldo - total);
        printf("\nArquivo gravado com sucesso\n");
    }
    fclose(arquivo_txt);
}

void txt_PorCat() {
    gerenciador g;
    FILE *arquivo_txt2;
    char nome_arquivo_txt[50];
    sprintf(nome_arquivo_txt, "financas/%s%04d%02d.txt", g.categoria,g.ano, g.mes);
    printf("\nnome do arquivo: %s\n", nome_arquivo_txt);
    arquivo_txt2 = fopen(nome_arquivo_txt, "a");
    if (arquivo_txt2 == NULL) {
        printf("\nErro ao abrir o arquivo\n");
    } else {
        //fprintf(arquivo_txt, "Saldo: %.2f", g.saldo);
        fprintf(arquivo_txt2, "Data: %02d/%02d/%04d\n", g.dia, g.mes, g.ano);
        fprintf(arquivo_txt2, "Categoria: %s\n", g.categoria);
        fprintf(arquivo_txt2, "Descricao: %s\n", g.descricao);
        fprintf(arquivo_txt2, "Valor: %.2f\n", g.valor);
        //fprintf(arquivo_txt, "Total a pagar: %.2f", g.saldo - total);
        printf("\nArquivo gravado com sucesso\n");
    }
    fclose(arquivo_txt2);

}

void menu(){
    int n;
    do{
        printf("\n----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
        printf("Digite a opção desejada: \n 0-Sair\n 1-Cadastar Usuario\n 2-Gerar relatorio do ultimo mes\n 3-Gerar relatorio dos ultimos 12 meses\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&n);


        switch (n)
        {
            case 0:
                printf("OK... Saindo...\n");
                break;
            case 1:
                printf("---------OPÇÃO 1 -----------\n");
                cadastrar();
                arquivo_binário();
                relatorioPorCat();
                passar_txt();
                txt_PorCat();
                break;
            case 2:
                printf("---------OPÇÃO 2 -----------\n");
                relatorio_ultimoMes();
                //ler_binário();
                //passar_txt();
                break;
            case 3:
                printf("---------OPÇÃO 3 -----------\n");
                relatorio_12meses();
                break;
            default:
                printf("\033c");
                printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                return menu();
        }
    }
    while (n !=0);
    printf("----------------------------------------------------------\n");
}

int main(){
    menu();
}