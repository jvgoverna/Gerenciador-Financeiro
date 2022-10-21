#include <stdio.h>
#include "funcoes.h"

//menu de opcoes

struct gerenciador_finaceiro gerenciador_financas;

struct gerenciador_finaceiro relatorio_lido;

void menu() {
    int opcao;
    do {
        printf("----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar Saldo\n");
        printf("2 - Cadastrar despesas\n");
        printf("3 - Gerar relatorio\n");
        printf("4 - Forma de pagamento\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;
            case 1:
                receita();
                break;
            case 2:
                despesas();
                break;
            case 3:
                relatorio(despesas(&gerenciador_financas));
                break;
                //case 4:
                //formaPagamento(gereciadorFinancas);
                //break;
            default:
                printf("ERRO!! opcao invalida, Digite uma opcao valida!\n");
                return menu();
        }
    } while (opcao != 0);
    printf("----------------------------------------------------------");
}

void mes_anterior(int ano,int mes,int *ano_a,int *mes_a){
    if(mes == 1){
        ano_a -= 1;
        mes_a = 12;
    }else{
        ano_a = ano;
        mes_a = mes - 1;
    }
}

double receita(){

    struct gerenciador_finaceiro gerenciador_financas;

    printf("Digite o Nome: ");
    scanf("%s", gerenciador_financas.nome);
    printf("Digite o Sobrenome: ");
    scanf("%s", gerenciador_financas.sobrenome);
    printf("Digite o saldo Inical: ");
    scanf("%lf", gerenciador_financas.saldo);


    FILE *f ;
    
    char *caminho;
    
    for (int i = 0; i < 12; i++)
    {
        mes_anterior( ano, mes,*ano_a,*mes_a);
        sprintf(caminho,"relatorio_%d_%d.bin", ano, mes);
        f = fopen(caminho,"wb");
    }
        
    }

    fwrite(&gerenciador_financas, sizeof(struct gerenciador_finaceiro), 1, f);

    fclose(f);

    return gerenciador_financas.saldo;
}

double despesas(){

    struct gerenciador_finaceiro gerenciador_financas;

    double total = 0;
    printf("Digite a categoria: ");
    scanf("%s", gerenciador_financas.categoria);
    printf("Digite a descrição: ");
    scanf("%s", gerenciador_financas.descricao);
    printf("Digite o valor: ");
    scanf("%lf", &gerenciador_financas.valor);
    printf("Digite o dia: ");
    scanf("%d", &gerenciador_financas.dia);
    printf("Digite o mês: ");
    scanf("%d", &gerenciador_financas.mes);
    printf("Digite o ano: ");
    scanf("%d", &gerenciador_financas.ano);

    total += gerenciador_financas.valor;

    FILE *f = fopen("despesas.bin", "ab");

    fwrite(&gerenciador_financas, sizeof(struct gerenciador_finaceiro), 1, f);

    fclose(f);

    return total;
}

void relatorio(double total){

    struct gerenciador_finaceiro gerenciador_financas;

    FILE *fr = fopen("despesas.bin", "rb");

    fread(&relatorio_lido, sizeof(struct gerenciador_finaceiro), 1, fr);

    fclose(fr);

    printf("Categoria: %s\n", gerenciador_financas.categoria);
    printf("Descrição: %s\n", gerenciador_financas.descricao);
    printf("Valor: %lf\n", gerenciador_financas.valor);
    printf("Data: %d/%d/%d\n", gerenciador_financas.dia, gerenciador_financas.mes, gerenciador_financas.ano);
    printf("Total: %lf\n", total);

    FILE *ftxt = fopen("relatorio.txt", "a");

    fprintf(ftxt, "Categoria: %s\n", gerenciador_financas.categoria);
    fprintf(ftxt, "Descrição: %s\n", gerenciador_financas.descricao);
    fprintf(ftxt, "Valor: %lf\n", gerenciador_financas.valor);
    printf("Data: %d/%d/%d\n", gerenciador_financas.dia, gerenciador_financas.mes, gerenciador_financas.ano);
    fprintf(ftxt, "Total: %lf\n", total);

    fclose(ftxt);
}

//void Forma_Pagamento(struct gerenciador_finaceiro *gerenciadorFinancas, double total){
// printf("Forma de pagamento: ");
//scanf("%s", gerenciadorFinancas->formaPagamento);
// printf("Valor pago: ");
// scanf("%lf", &gerenciadorFinancas->valorPago);
// printf("Troco: %lf", gerenciadorFinancas->valorPago - total);
//}

