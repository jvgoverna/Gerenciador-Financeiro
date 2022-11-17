#include <stdio.h>
#include <math.h>

typedef struct {
    char descricao[30];
    char categoria[30];
    float preco;
    int dia,mes,ano;
    float total;
}gerenciador;

typedef struct {
    float valor;
    int dia,mes,ano;
    float juros;
    float rendimento;
}poupanca;

//funcao de cadastrar as despesas

void cadastrar(){
    gerenciador despesa;
    printf("Digite a descricao da despesa:\n");
    scanf("%s",despesa.descricao);
    printf("Digite a categoria da despesa:\n");
    scanf("%s",despesa.categoria);
    printf("Digite o preco da despesa:\n");
    scanf("%f",&despesa.preco);
    printf("Digite o dia da despesa:\n");
    scanf("%d",&despesa.dia);
    printf("Digite o mes da despesa:\n");
    scanf("%d",&despesa.mes);
    printf("Digite o ano da despesa:\n");
    scanf("%d",&despesa.ano);
    despesa.total += despesa.preco;

    FILE *arq;
    char nome_arq[30];

    sprintf(nome_arq, "financas/%04d-%02d", despesa.ano,despesa.mes);
    arq = fopen(nome_arq, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq);
    }
    fclose(arq);

    FILE *arq_txt;
    char nome_arq_txt[30];

    sprintf(nome_arq_txt, "financas/%04d-%02d.txt", despesa.ano,despesa.mes);
    arq_txt = fopen(nome_arq_txt, "a");
    if (arq_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_txt, "\nDescricao: %s\n", despesa.descricao);
        fprintf(arq_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq_txt, "Preco: %.2lf\n", despesa.preco);
        fprintf(arq_txt, "Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
    }
    fclose(arq_txt);

    FILE *arq2;

    sprintf(nome_arq,"financas/%s-%04d-%02d", despesa.categoria,despesa.ano,despesa.mes);
    arq2 = fopen(nome_arq, "ab");
    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq2);
    }
    fclose(arq2);

    FILE *arq2_txt;

    sprintf(nome_arq_txt, "financas/%s-%04d-%02d.txt", despesa.categoria,despesa.ano,despesa.mes);
    arq2_txt = fopen(nome_arq_txt, "a");
    if (arq2_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq2_txt, "Descricao: %s\n", despesa.descricao);
        fprintf(arq2_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq2_txt, "Preco: %.2lf\n", despesa.preco);
        fprintf(arq2_txt, "Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
    }
    fclose(arq2_txt);

    FILE *arq3;

    sprintf(nome_arq,"financas/%04d", despesa.ano);
    arq3 = fopen(nome_arq, "ab");
    if (arq3 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq3);
    }
    fclose(arq3);

    FILE *arq3_txt;

    sprintf(nome_arq_txt, "financas/%04d.txt", despesa.ano);
    arq3_txt = fopen(nome_arq_txt, "a");
    if (arq3_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq3_txt, "Descricao: %s\n", despesa.descricao);
        fprintf(arq3_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq3_txt, "Preco: %.2lf\n", despesa.preco);
        fprintf(arq3_txt, "Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
    }
    fclose(arq3_txt);

    FILE *arq_total;

    sprintf(nome_arq,"financas/total");
    arq_total = fopen(nome_arq, "wb");
    if (arq_total == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq_total);
    }
    fclose(arq_total);

    FILE *arq_total_txt;

    sprintf(nome_arq_txt, "financas/total.txt");
    arq_total_txt = fopen(nome_arq_txt, "w");
    if (arq_total_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_total_txt, "Total Gasto: %.2f\n", despesa.total);
    }
    fclose(arq_total_txt);
}

void relatorio_ultimoMes(){
    gerenciador despesa;
    FILE *arq2;
    char nome_arq[30];

    printf("Digite a categoria desejada:");
    scanf("%s", despesa.categoria);
    printf("Digite o mes atual: ");
    scanf("%d", &despesa.mes);
    printf("Digite o ano atual: ");
    scanf("%d", &despesa.ano);

    sprintf(nome_arq,"financas/%s-%04d-%02d", despesa.categoria,despesa.ano,despesa.mes-1);
    arq2 = fopen(nome_arq, "rb");
    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&despesa, sizeof(gerenciador), 1, arq2) != 0){
            printf("\nDescricao: %s\n", despesa.descricao);
            printf("Categoria: %s\n", despesa.categoria);
            printf("Preco: %.2f\n", despesa.preco);
            printf("Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
        }
    }
    fclose(arq2);
}

void relatorio_12Meses(){
    gerenciador despesa;
    FILE *arq3;
    char nome_arq[30];

    printf("Digite o ano: ");
    scanf("%d", &despesa.ano);

    sprintf(nome_arq,"financas/%04d", despesa.ano);
    arq3 = fopen(nome_arq, "rb");
    if (arq3 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&despesa, sizeof(gerenciador), 1, arq3) != 0){
            printf("\nDescricao: %s\n", despesa.descricao);
            printf("Categoria: %s\n", despesa.categoria);
            printf("Preco: %.2f\n", despesa.preco);
            printf("Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
        }
    }
    fclose(arq3);
}

void total(){
    gerenciador despesa;
    FILE *arq_total;
    char nome_arq[30];

    sprintf(nome_arq,"financas/total");
    arq_total = fopen(nome_arq, "rb");
    if (arq_total == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&despesa, sizeof(gerenciador), 1, arq_total) != 0){
            printf("Total Gasto: %.2f\n", despesa.total);
        }
    }
    fclose(arq_total);
}

//POUPANÇA

void cadastrar_poupanca(){
    poupanca p;
    FILE *arq_poupanca;
    char nome_arq[30];

    printf("Digite o valor: ");
    scanf("%f", &p.valor);
    printf("Digite o dia: ");
    scanf("%d", &p.dia);
    printf("Digite o mes: ");
    scanf("%d", &p.mes);
    printf("Digite o ano: ");
    scanf("%d", &p.ano);

    sprintf(nome_arq,"financas/poupanca-%04d-%02d", p.ano,p.mes);
    arq_poupanca = fopen(nome_arq, "ab");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&p, sizeof(poupanca), 1, arq_poupanca);
        printf("Poupanca cadastrada com sucesso!\n");
    }
    fclose(arq_poupanca);

    FILE *arq_poupanca_txt;

    sprintf(nome_arq, "financas/poupanca-%04d-%02d.txt", p.ano,p.mes);
    arq_poupanca_txt = fopen(nome_arq, "a");
    if (arq_poupanca_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_poupanca_txt, "Valor Inicial: %.2f\n", p.valor);
        fprintf(arq_poupanca_txt, "Data: %02d/%02d/%04d\n", p.dia,p.mes,p.ano);
        printf("Poupanca cadastrada com sucesso!\n");
    }
    fclose(arq_poupanca_txt);
}

void relatorio_poupanca(){
    poupanca p;
    FILE *arq_poupanca;
    char nome_arq[30];

    printf("Digite o mes: ");
    scanf("%d", &p.mes);
    printf("Digite o ano: ");
    scanf("%d", &p.ano);

    sprintf(nome_arq,"financas/poupanca-%04d-%02d", p.ano,p.mes);
    arq_poupanca = fopen(nome_arq, "rb");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&p, sizeof(poupanca), 1, arq_poupanca) != 0){
            printf("Valor Inicial: %.2f\n", p.valor);
            printf("Data: %02d/%02d/%04d", p.dia,p.mes,p.ano);
        }
    }
    fclose(arq_poupanca);

}

void relatorio_poupanca_12meses(){
    poupanca p;
    float taxa = 0.05;
    float montante = p.valor * pow((1 + taxa), 12);
    p.juros = montante - p.valor;
    p.rendimento = p.valor + p.juros;

    FILE *arq_poupanca;
    char nome_arq[30];

    sprintf(nome_arq, "financas/poupanca-%04d-%02d", p.ano,p.mes);
    arq_poupanca = fopen(nome_arq, "ab");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&p, sizeof(poupanca), 1, arq_poupanca);
        printf("Poupanca cadastrada com sucesso!\n");
    }
    fclose(arq_poupanca);

    FILE *arq_poupanca_txt;

    sprintf(nome_arq, "financas/poupanca-%04d-%02d.txt", p.ano,p.mes);
    printf("Nome do arquivo: %s\n", nome_arq);
    arq_poupanca_txt = fopen(nome_arq, "a");
    if (arq_poupanca_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else {
        fprintf(arq_poupanca_txt, "Rendimento após 12 meses: %.2f", p.rendimento);
        printf("Poupanca cadastrada com sucesso!\n");
    }
    fclose(arq_poupanca_txt);
}

void poupancas(){
    int opcao;
        do{
            printf("\n-----------Poupança-----------\n");
            printf("1 - Cadastrar Poupança\n");
            printf("2 - Relatório de Poupança\n");
            printf("3 - Relatório de Poupança após 12 meses\n");
            printf("-------------------------------\n");
            printf("Digite a opção desejada:\n");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    cadastrar_poupanca();
                    break;
                case 2:
                    relatorio_poupanca();
                    break;
                case 3:
                    relatorio_poupanca_12meses();
                    break;
                default:
                    printf("\033c");
                    printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                    break;
            }
    }
    while(opcao != 0);
    printf("----------------------------------------------------------\n");
}


void menu(){
    int n;
    do {
        printf("\n----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
        printf("Digite a opção desejada: \n 0-Sair\n 1-Cadastar Despesas\n 2-Gerar relatorio do ultimo mes\n 3-Gerar relatorio dos ultimos 12 meses\n 4-Exibir valor total gasto em 12 meses\n 5-Poupança\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&n);
        switch(n){
            case 0:
                printf("OK... Saindo...\n");
                break;
            case 1:
                printf("---------OPÇÃO 1 -----------\n");
                cadastrar();
                break;
            case 2:
                printf("---------OPÇÃO 2 -----------\n");
                relatorio_ultimoMes();
                break;
            case 3:
                printf("---------OPÇÃO 3 -----------\n");
                relatorio_12Meses();
                break;
            case 4:
                printf("---------OPÇÃO 4 -----------\n");
                total();
                break;
            case 5:
                poupancas();
                break;
            default:
                printf("\033c");
                printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                return menu();
        }
    }
    while(n != 0);
    printf("----------------------------------------------------------\n");
}
int main(){
    menu();
    return 0;
}
