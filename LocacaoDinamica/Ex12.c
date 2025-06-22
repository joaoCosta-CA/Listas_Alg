#include <stdio.h>
#include <stdlib.h>

void escolher(int *memoria){
    int escolha;
    for(int i=0;i<1;){
        printf("\n");
        printf("------- OPECOES -------\n");
        printf("0- Sair\n");
        printf("1- Inserir dados no endereco.\n");
        printf("2- Acessar dados do endereco.\n");
        scanf("%d", &escolha);

        if(escolha==0){
            puts("Saida com sucesso!");
            exit(0);
        
        }else if(escolha==1){
            puts("Insira o valor dentro do endereco:");
            scanf("%d", memoria);
        }else if(escolha==2){
            printf("Endereco:%p\n", (void *)memoria);
            printf("Valor:%d", *memoria);
        }

    }
}

int main(){
    int bytes;

    puts("Qunatos bytes quer na sua memoria:");
    scanf("%d", &bytes);

    int *memoria=(int *)calloc(bytes,sizeof(int));

    escolher(memoria);

    free(memoria);

    return 0;
}