#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    char end[50];
}Cadastro;

Cadastro* retornaPonteiro(int N){

    Cadastro *vet= (Cadastro *)malloc(N*sizeof(Cadastro));

    if(vet==NULL){
        printf("Erro, nenhum conteudo alocado!");
    }else{
        for(int i=0;i<N;i++){
            setbuf(stdin,NULL);
            printf("Digite seu nome:");
            fgets(vet[i].nome,50,stdin);

            printf("Digite a idade:");
            scanf("%d", &vet[i].idade);
            setbuf(stdin,NULL);

            printf("Digite o nome do seu enderco:");
            fgets(vet[i].end,50,stdin);
        }
    }

    return vet;
}

int main(){
    struct Cadastro;
    int N;

    printf("Digite qunatas vezes quer cadastrar alguem:");
    scanf("%d", &N);

    Cadastro *cad= retornaPonteiro(N);

    if(cad!=NULL){
        for(int i=0;i<N;i++){
            printf("Nome: %s", cad[i].nome);
            printf("Idade: %d\n", cad[i].idade);
            printf("Endereco: %s", cad[i].end);
            printf("\n");
        }
    }

    free(cad);

    return 0;
}