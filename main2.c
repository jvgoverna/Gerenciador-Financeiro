#include <stdio.h>

typedef struct{
    char nome[50];
    char sobrenome[50];
    char descrição[30];
    char categoria[30];
    double valor;
    int dia,mes,ano;
}gerenciador;
void desc(void *d){ //Funcao utilizada para receber varias strings do usuario
    scanf(" %99[^\n]", d);
}
void cadastrar(){
    gerenciador g;
    printf("Digite seu nome:\n");
    desc(&g.nome);
    printf("Digite seu sobrenome:\n");
    desc(&g.sobrenome);
    printf("Digite a descrição: \n");
    desc(&g.descrição);
    printf("Digite a categoria: \n");
    desc(&g.categoria);
    printf("Digite o valor que será colocado: \n");
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
    printf("Digite o mes:");
    scanf("%d", &g.mes);
    printf("Digite o ano:");
    scanf("%d", &g.ano);
    sprintf(nome_arquivo, "financas/%d/%d", &g.mes, &g.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
    } else {
        fwrite(&g, sizeof(gerenciador), 1, arquivo);
        fclose(arquivo);
    }
}

void ler_binário(){
    gerenciador g;
    FILE *arquivo;
    char nome_arquivo[50];
    printf("Digite o mes:");
    scanf("%d", &g.mes);
    printf("Digite o ano:");
    scanf("%d", &g.ano);
    sprintf(nome_arquivo, "financas/%d/%d", &g.mes, &g.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
    } else {
        while (fread(&g, sizeof(g), 1, arquivo)) {
            printf("Nome: %s %s", g.nome, g.sobrenome);
            //printf("Saldo: %.2f", g.saldo);
            printf("Data: %02d/%02d/%02d\n", g.dia, g.mes, g.ano);
            printf("Categoria: %s\n", g.categoria);
            printf("Descricao: %s\n", g.descrição);
            printf("Valor: %.2f\n", g.valor);
            //total += relatorio_lido.valor;
        }
        //printf("Total a pagar: %.2f", g.saldo - total);
        fclose(arquivo);
    }
}

void passar_txt(){
    gerenciador g;
    FILE *arquivo_txt;
    char nome_arquivo_txt[50];
    sprintf(nome_arquivo_txt, "financas/%d/%d.txt", &g.mes, &g.ano);
    printf("nome do arquivo: %s\n", nome_arquivo_txt);
    arquivo_txt = fopen(nome_arquivo_txt, "a");
    if (arquivo_txt == NULL) {
        printf("\nErro ao abrir o arquivo");
    } else {
        fprintf(arquivo_txt, "Nome: %s %s", g.nome, g.sobrenome);
        //fprintf(arquivo_txt, "Saldo: %.2f", g.saldo);
        fprintf(arquivo_txt, "Data: %02d/%02d/%02d", g.dia, g.mes, g.ano);
        fprintf(arquivo_txt, "Categoria: %s", g.categoria);
        fprintf(arquivo_txt, "Descricao: %s", g.descrição);
        fprintf(arquivo_txt, "Valor: %.2f", g.valor);
        //fprintf(arquivo_txt, "Total a pagar: %.2f", g.saldo - total);
        fclose(arquivo_txt);
    }
}

void relatorio_ultimoMes(){
    gerenciador g;
    printf("Digite o mes e ano que deseja ver o relatorio:");
    scanf("%d %d", &g.mes, &g.ano);
    FILE *arquivo;
    char nome_arquivo[50];
    sprintf(nome_arquivo, "financas/%d/%d", &g.mes, &g.ano);
    printf("nome do arquivo: %s", nome_arquivo);
    arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
    } else {
        while (fread(&g, sizeof(g), 1, arquivo)) {
            printf("Nome: %s %s", g.nome, g.sobrenome);
            //printf("Saldo: %.2f", g.saldo);
            printf("Data: %02d/%02d/%02d\n", g.dia, g.mes, g.ano);
            printf("Categoria: %s\n", g.categoria);
            printf("Descricao: %s\n", g.descrição);
            printf("Valor: %.2f\n", g.valor);
            //total += relatorio_lido.valor;
        }
        //printf("Total a pagar: %.2f", g.saldo - total);
        fclose(arquivo);
    }
}

void menu(){
    int n;
    do{
        printf("----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
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
                passar_txt();
                break;
            case 2:
                printf("---------OPÇÃO 2 -----------\n");
                relatorio_ultimoMes();
                //ler_binário();
                //passar_txt();
                break;
            case 3:
                printf("---------OPÇÃO 3 -----------\n");
                ler_binário();
                passar_txt();
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