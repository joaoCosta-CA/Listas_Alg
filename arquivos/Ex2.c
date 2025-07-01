#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    char nome[50];
    double preco;
    int quant;
};

void PrecoFinal(FILE *arq, struct Produto produtos[]){
    int i=0;
    double preco=0;

    while(fscanf(arq,"%s %lf %d",produtos[i].nome,&produtos[i].preco, &produtos[i].quant)==3){
        preco+=produtos[i].preco*produtos[i].quant;
        i++;
    }

    printf("Preco final: %.2lf\n", preco);
}

void lerProduto(struct Produto produtos[], FILE *arq){
    for(int i=0;i<5;i++){
        setbuf(stdin,NULL);

        puts("Nome:");
        fgets(produtos[i].nome, 50, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        puts("preco:");
        scanf("%lf", &produtos[i].preco);

        puts("Quantidade:");
        scanf("%d", &produtos[i].quant);

        fprintf(arq, " %s %.2lf %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quant);
    }
  
}

void excluir(){
    int exclude;
    int op;

    puts("Excluir arquivo? (1-Sim / 0-Nao)");
    scanf("%d", &op);
    if (op){
        exclude = remove("Lista.txt");
        if (exclude != 0){
            puts("Erro ao excluir");
            exit(1);
        }else{
            puts("Arquivo removido!");
        }
    }
}

int main(){
    struct Produto produtos[5];


    FILE *arq= fopen("Lista.txt", "w");
    if (arq == NULL){
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    lerProduto(produtos, arq);
    fclose(arq);

    arq=fopen("Lista.txt", "r");

    PrecoFinal(arq, produtos);
    fclose(arq);
    excluir();

    return 0;
}