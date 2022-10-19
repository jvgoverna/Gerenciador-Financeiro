#include <stdio.h>

typedef struct{
    char nome[50];
    char sobrenome[50];
    char descrição[30];
    char categoria[30];
    double valor;
    int dia,mes,ano;
}gerenciador;

void cadastrar(){
    gerenciador g;
    printf("Digite seu nome:\n");
    scanf("%s",g.nome);
    printf("Digite seu sobrenome:\n");
    scanf("%s",g.sobrenome);
    printf("Digite a descrição: \n");
    scanf("%s",g.descrição);
    printf("Digite a categoria: \n");
    scanf("%s",g.categoria);
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
    FILE *arq = fopen("cadastro.bin","wb");
    fwrite(&g,sizeof(gerenciador),1,arq);
    fclose(arq);
}

void ler_binário(){
    gerenciador g;
    FILE *arq = fopen("cadastro.bin","rw");
    fread(&g,sizeof(gerenciador),1,arq);
    fclose(arq);
    printf("Nome inteiro: %s %s\n",g.nome,g.sobrenome);
    printf("Descrição: %s\n",g.descrição);
    printf("Categoria: %s\n",g.categoria);
    printf("Valor: %.2lf\n",g.valor);
    printf("Data: %d/%d/%d\n",g.dia,g.mes,g.ano);
}

void passar_txt(){
    gerenciador g;
    FILE *arq = fopen("cadastro.txt","a+");
    fprintf(arq,"Nome inteiro: %s %s\n",g.nome,g.sobrenome);
    fprintf(arq,"Descrição: %s\n",g.descrição);
    fprintf(arq,"Categoria: %s\n",g.categoria);
    fprintf(arq,"Valor: %.2lf\n",g.valor);
    fprintf(arq,"Data: %d/%d/%d\n",g.dia,g.mes,g.ano);
    fclose(arq);
}

void menu(){
    int n;
    do{
        printf("----------Bem Vindo ao Gerenciador financeiro!!-----------\n");
        printf("Digite a opção desejada: \n 0-sair\n 1-cadastar\n");
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
                ler_binário();
                passar_txt();
                break;

            default:
                printf("ERRO!! opção inválida, Digite uma opção válida!\n");
                return menu();
        }
    }
    while (n !=0);
    printf("----------------------------------------------------------");
}

int main(){
    menu();
}
