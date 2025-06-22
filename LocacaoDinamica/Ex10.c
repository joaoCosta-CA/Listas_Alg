#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro{
    int code;
    char nome[50];
    int quantidade;
    double valor;
};

void encontraroMaiorPreco(int n, struct cadastro produtos[]){
    double maior = produtos[0].valor;

    for (int i = 0; i < n; i++){
        if (produtos[i].valor > maior){
            maior = produtos[i].valor;
        }
    }

    printf("O maoir valor: %.2lfR$", maior);
    printf("\n");
}

void encontrarMaiorQnt(int n, struct cadastro produtos[]){
    int  maiorQnt=produtos[0].quantidade;

    for(int i=0;i<n;i++){
        if(produtos[i].quantidade>maiorQnt){
            maiorQnt=produtos[i].quantidade;
        }
    }

    printf("Maior quantidade = %d unidades", maiorQnt);
}

void cadastrarProduto(int n){
    struct cadastro *produtos=(struct cadastro*)malloc(n*sizeof(struct cadastro));
    if(produtos==NULL){
        printf("Erro na alocacao!");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        puts("Digite o codigo do produto");
        scanf("%d", &(*(produtos+i)).code);
        puts("Digite o nome do produto");
        setbuf(stdin, NULL);
        fgets((*(produtos+i)).nome, 50, stdin);
        strtok((*(produtos+i)).nome, "\n");
        puts("Digite a quantidade de produtos");
        scanf("%d", &(*(produtos+i)).quantidade);
        puts("Digite o valor do produto");
        scanf("%lf", &(*(produtos+i)).valor);
    }

    encontraroMaiorPreco(n, produtos);
    encontrarMaiorQnt(n, produtos);

    free(produtos);

}



int main(){
    int n;
    puts("Digite quantos produtos deseja");
    scanf("%d", &n);
    cadastrarProduto(n);

    return 0;
}