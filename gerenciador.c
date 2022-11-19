#include <stdio.h>
#include <math.h>

//struct para armazenar as despesas

typedef struct {
    char descricao[30];
    char categoria[30];
    float preco;
    int dia,mes,ano;
    float total;
}gerenciador;

//struct para armazenar as informações da poupança

typedef struct {
    float valor;
    int diap,mesp,anop;
    float juros;
    float rendimento;
    float valor_final;
}poupanca;

//Funcao utilizada para receber varias strings do usuario

void desc(void *d){ 
    scanf(" %99[^\n]", d);
}

//funcao de cadastrar as despesas e escrever os dados no arquivo binario e passar para o txt

//criar pasta financas para rodar o programa

void cadastrar(){ 
    gerenciador despesa;
    printf("Digite a descricao da despesa: ");
    desc(&despesa.descricao);
    printf("Digite a categoria da despesa: ");
    desc(&despesa.categoria);
    printf("Digite o preco da despesa: ");
    scanf("%f",&despesa.preco);
    printf("Digite o dia da despesa: ");
    scanf("%d",&despesa.dia);
    printf("Digite o mes da despesa: ");
    scanf("%d",&despesa.mes);
    printf("Digite o ano da despesa: ");
    scanf("%d",&despesa.ano);
    despesa.total = despesa.total + despesa.preco;

    FILE *arq; // arquivo binario que armazena despesas por ano e mes inseridos pelo usuario.
    char nome_arq[30]; //lista para armazenar o nome dos arquivos binarios

    sprintf(nome_arq, "financas/%04d-%02d", despesa.ano,despesa.mes);
    arq = fopen(nome_arq, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq);
    }
    fclose(arq);

    FILE *arq_txt; // arquivo txt que armazena despesas por ano e mes inseridos pelo usuario.
    char nome_arq_txt[30]; //lista para armazenar o nome dos arquivos txt

    sprintf(nome_arq_txt, "financas/%04d-%02d.txt", despesa.ano,despesa.mes);
    arq_txt = fopen(nome_arq_txt, "a");
    if (arq_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_txt, "Descricao: %s\n", despesa.descricao);
        fprintf(arq_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq_txt, "Preco: R$%.2f\n", despesa.preco);
        fprintf(arq_txt, "Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
        fprintf(arq_txt, "\n");
    }
    fclose(arq_txt);

    FILE *arq2; // arquivo binário que armazena despesas por categoria,ano e mes inseridos pelo usuario.

    sprintf(nome_arq,"financas/%s-%04d-%02d", despesa.categoria,despesa.ano,despesa.mes);
    arq2 = fopen(nome_arq, "ab");
    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq2);
    }
    fclose(arq2);

    FILE *arq2_txt; // arquivo txt que armazena despesas por categoria,ano e mes inseridos pelo usuario.

    sprintf(nome_arq_txt, "financas/%s-%04d-%02d.txt", despesa.categoria,despesa.ano,despesa.mes);
    arq2_txt = fopen(nome_arq_txt, "a");
    if (arq2_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq2_txt, "Descricao: %s\n", despesa.descricao);
        fprintf(arq2_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq2_txt, "Preco: R$%.2f\n", despesa.preco);
        fprintf(arq2_txt, "Data: %02d/%02d/%04d\n\n", despesa.dia,despesa.mes,despesa.ano);
        fprintf(arq_txt, "\n");

    }
    fclose(arq2_txt);

    FILE *arq3; // arquivo binário que armazena as despesas por ano inserido pelo usuario.

    sprintf(nome_arq,"financas/%04d", despesa.ano);
    arq3 = fopen(nome_arq, "ab");
    if (arq3 == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq3);
    }
    fclose(arq3);

    FILE *arq3_txt; // arquivo txt que armazena as despesas por ano inserido pelo usuario.

    sprintf(nome_arq_txt, "financas/%04d.txt", despesa.ano);
    arq3_txt = fopen(nome_arq_txt, "a");
    if (arq3_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq3_txt, "Descricao: %s\n", despesa.descricao);
        fprintf(arq3_txt, "Categoria: %s\n", despesa.categoria);
        fprintf(arq3_txt, "Preco: R$%.2f\n", despesa.preco);
        fprintf(arq3_txt, "Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
        fprintf(arq_txt, "\n");

    }
    fclose(arq3_txt);

    FILE *arq_total; // arquivo binário que armazena o total gasto nos 12 meses pelo usuario.

    sprintf(nome_arq,"financas/total");
    arq_total = fopen(nome_arq, "wb");
    if (arq_total == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&despesa, sizeof(gerenciador), 1, arq_total);
    }
    fclose(arq_total);

    FILE *arq_total_txt; // arquivo txt que armazena o total gasto nos 12 meses pelo usuario.

    sprintf(nome_arq_txt, "financas/total.txt");
    arq_total_txt = fopen(nome_arq_txt, "w");
    if (arq_total_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_total_txt, "Total Gasto: R$%.2f\n", despesa.total);
    }
    fclose(arq_total_txt);
}

//Função que exibe o relatório de gastos do mês anterior ao atual.

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

    //verifica o mes: se for digitado 1, o mes anterior é 12, se for 2, o mes anterior é 1 e assim por diante.

    if(despesa.mes == 1){
        despesa.mes = 12;
        despesa.ano = despesa.ano - 1;
        sprintf(nome_arq,"financas/%s-%04d-%02d", despesa.categoria,despesa.ano,despesa.mes);
        arq2 = fopen(nome_arq, "rb");
        if (arq2 == NULL) {
            printf("Erro ao abrir o arquivo");
            return;
        } else{
        while(fread(&despesa, sizeof(gerenciador), 1, arq2) != 0){
                printf("Descricao: %s\n", despesa.descricao);
                printf("Categoria: %s\n", despesa.categoria);
                printf("Preco: R$%.2f\n", despesa.preco);
                printf("Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
                printf("\n");
            }
        }
    } else{
        despesa.mes = despesa.mes - 1;
        sprintf(nome_arq,"financas/%s-%04d-%02d", despesa.categoria,despesa.ano,despesa.mes);
        arq2 = fopen(nome_arq, "rb");
        if (arq2 == NULL) {
            printf("Erro ao abrir o arquivo");
            return;
        } else{
        while(fread(&despesa, sizeof(gerenciador), 1, arq2) != 0){
                printf("Descricao: %s\n", despesa.descricao);
                printf("Categoria: %s\n", despesa.categoria);
                printf("Preco: R$%.2f\n", despesa.preco);
                printf("Data: %02d/%02d/%04d\n", despesa.dia,despesa.mes,despesa.ano);
                printf("\n");
            }
        }
    }
}

//Função que exibe o relatorio de gasto no período de 12 meses.

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
            printf("Descricao: %s\n", despesa.descricao);
            printf("Categoria: %s\n", despesa.categoria);
            printf("Preco: R$%.2f\n", despesa.preco);
            printf("Data: %02d/%02d/%04d\n\n", despesa.dia,despesa.mes,despesa.ano);
        }
    }
    fclose(arq3);
}

//Funcao que exibe o total gasto com as despesas no período de 12 meses.

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
            printf("Total Gasto: R$%.2f\n", despesa.total);
        }
    }
    fclose(arq_total);
}

//Função que cadastra os valores e datas de inicio da Poupança

void cadastrar_poupanca(){
    poupanca p;
    FILE *arq_poupanca; // arquivo binario que armazena os dados da poupança.
    char nome_arq[30];
    char nome_arq_txt[30];

    printf("Digite o valor: ");
    scanf("%f", &p.valor);
    printf("Digite o dia: ");
    scanf("%d", &p.diap);
    printf("Digite o mes: ");
    scanf("%d", &p.mesp);
    printf("Digite o ano: ");
    scanf("%d", &p.anop);

    //calculo do rendimento anual da poupança através da taxa de 5% ao ano

    float rendimento = 0.0;
    float taxa = 0.05;
    float valor = p.valor;
    int i = 0;

    for(i = 0; i < 12; i++){
        rendimento = valor * taxa;
        valor = valor + rendimento;
    }

    p.rendimento = rendimento;
    float valor_final = 0.0;

    valor_final = p.valor + p.rendimento;
    p.valor_final = valor_final;

    //arquivo binario que armazena as informações da poupança

    sprintf(nome_arq,"financas/poupanca-%04d", p.anop);
    arq_poupanca = fopen(nome_arq, "ab");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fwrite(&p, sizeof(poupanca), 1, arq_poupanca);
    }
    fclose(arq_poupanca);

    FILE *arq_poupanca_txt; // arquivo txt que armazena os dados da poupança.

    sprintf(nome_arq_txt, "financas/poupanca-%04d.txt", p.anop);
    arq_poupanca_txt = fopen(nome_arq_txt, "a");
    if (arq_poupanca_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_poupanca_txt, "Valor Inicial: R$%.2f\n", p.valor);
        fprintf(arq_poupanca_txt, "Data: %02d/%02d/%04d\n", p.diap,p.mesp,p.anop);
        fprintf(arq_poupanca_txt, "Rendimento após 12 meses será de: R$%.2lf\n", p.rendimento);
    }
    fclose(arq_poupanca_txt);
}

// Função que exibe o rendimento da poupança em um período de 12 meses. 

void rendimento_poupanca_12meses(){
    poupanca p;
    FILE *arq_poupanca;
    char nome_arq[30];

    printf("Digite o ano: ");
    scanf("%d", &p.anop);

    sprintf(nome_arq, "financas/poupanca-%04d", p.anop);
    arq_poupanca = fopen(nome_arq, "rb");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&p, sizeof(poupanca), 1, arq_poupanca) != 0){
            printf("Rendimento após 12 meses será de: R$%.2lf\n", p.rendimento);
        }
    }
    fclose(arq_poupanca);
}

//Função que exibe o valor final da poupança. E escreve o valor final no arquivo txt.

void val_Fim_poup(){
    poupanca p;
    FILE *arq_poupanca;
    char nome_arq[30];

    printf("Digite o ano: ");
    scanf("%d", &p.anop);

    sprintf(nome_arq, "financas/poupanca-%04d", p.anop);
    arq_poupanca = fopen(nome_arq, "rb");
    if (arq_poupanca == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        while(fread(&p, sizeof(poupanca), 1, arq_poupanca) != 0){
            printf("\nValor final será de: R$%.2lf\n",p.valor_final);
        }
    }
    fclose(arq_poupanca);

    FILE *arq_poupanca_txt;
    char nome_arq_txt[30];

    sprintf(nome_arq_txt, "financas/poupanca-%04d.txt", p.anop);
    arq_poupanca_txt = fopen(nome_arq_txt, "a");
    if (arq_poupanca_txt == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    } else{
        fprintf(arq_poupanca_txt, "Valor final será de: R$%.2lf\n",p.valor_final);
    }
    fclose(arq_poupanca_txt);
}

//funcao que apaga os arquivos binarios e txt criados pelo programa

void apagar_poupanca(){
    char nome_arq[30];
    char nome_arq_txt[30];
    int ano;

    printf("Digite o ano que deseja apagar: ");
    scanf("%d", &ano);

    sprintf(nome_arq, "financas/poupanca-%04d", ano);
    remove(nome_arq);

    sprintf(nome_arq_txt, "financas/poupanca-%04d.txt", ano);
    remove(nome_arq_txt);
}

// Função que inicializa a poupança.

void poupancas(){
    int opcao;
        do{
            printf("\n-----------Poupança-----------\n");
            printf("0 - Sair\n");
            printf("1 - Cadastrar Poupança\n");
            printf("2 - Rendimento da Poupança após 12 meses\n");
            printf("3 - Exibir Valor final\n");
            printf("4 - Apagar dados da Poupança\n");
            printf("-------------------------------\n");
            printf("Digite a opção desejada:\n");
            scanf("%d", &opcao);

            switch(opcao){
                case 0:
                    printf("OK... Saindo...");
                    break;
                case 1:
                    cadastrar_poupanca();
                    break;
                case 2:
                    rendimento_poupanca_12meses();
                    break;
                case 3:
                    val_Fim_poup();
                    break;
                case 4:
                    apagar_poupanca();
                    break;
                default:
                    //printf("\033c");
                    printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                    break;
            }
    }
    while(opcao != 0);
    printf("\n----------------------------------------------------------\n");
}

//Função que inicializa o menu de opções do gerenciador financeiro.

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
                printf("---------OPÇÃO 5 -----------\n");
                poupancas();
                break;
            default:
                //printf("\033c");
                printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                return menu();
        }
    }
    while(n != 0);
    printf("----------------------------------------------------------\n");
}

//Função que inicia o programa.

int main(){
    menu();
    return 0;
}