#include <stdio.h>

typedef struct{
    char nome[50];
    char sobrenome[50];
    float valor;
    char descrição[30];
    char categoria[30];


}gerenciador;

void cadastrar(){
    gerenciador g;
    printf("Digite seu nome:\n");
    scanf("%s",g.nome);
    printf("Digite seu sobrenome:\n");
    scanf("%s",g.sobrenome);
    printf("Digite o valor que será colocado: ");
    scanf("%f",&g.valor);
    printf("Digite a descrição: ");
    scanf("%s",g.descrição);
    printf("Digite a categoria: ");
    scanf("%s",g.categoria);

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
    printf("Nome: %s\n",g.nome);
    printf("Sobrenome: %s\n",g.sobrenome);
    printf("Valor: %.2f\n",g.valor);
    printf("Descrição: %s\n",g.descrição);
    printf("Categoria: %s\n",g.categoria);
}

void passar_txt(){
    gerenciador g;
    FILE *arq = fopen("cadastro.txt","a");
    fprintf(arq,"Nome: %s\n",g.nome);
    fprintf(arq,"Sobrenome: %s\n",g.sobrenome);
    fprintf(arq,"Valor: %.2f\n",g.valor);
    fprintf(arq,"Descrição: %s\n",g.descrição);
    fprintf(arq,"Categoria: %s\n",g.categoria);
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
