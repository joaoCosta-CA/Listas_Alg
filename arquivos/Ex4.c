#include <stdio.h>
#include <stdlib.h>

void lerNumeros(FILE *arq){
    int linha,coluna;

    fscanf(arq, "%d %d", &linha, &coluna);

    int **matriz=calloc(linha,sizeof(int *));
    if(matriz==NULL){
        printf("Erro de alocacao");
        exit(1);
    }
    for(int i=0;i<linha;i++){
        matriz[i]=calloc(coluna,sizeof(int));
        if(matriz==NULL){
            puts("Erro de alocacao");
            exit(1);
        }
    }

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            fscanf(arq,"%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<linha;i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    FILE *arq=fopen("Numeros.txt", "r");
    if(arq==NULL){
        puts("Erro ao abrir arquivo");
        return 1;
    }

    lerNumeros(arq);
    fclose(arq);

    return 0;
}