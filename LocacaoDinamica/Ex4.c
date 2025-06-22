#include <stdio.h>
#include <stdlib.h>

int** preencher(int **mat, int linha,int coluna){
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            scanf("%d", &mat[i][j]);
        }
    }

    return mat;
}

int comparar(int **mat,int linha,int coluna,int N){
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(N==mat[i][j]){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int linha;
    int coluna;
    int **mat;
    int N;
    
    
    printf("Digite o numero que deseja vereficar");
    scanf("%d", &N);
    printf("Coloque o numero de linhas:");
    scanf("%d", &linha);
    printf("Coloque o numero de Colunas:");
    scanf("%d", &coluna);

    if(linha<=0 || coluna<=0){
        printf("Coloque valores que sejam maior que 0");
    }

    mat=(int **)malloc(linha*sizeof(int));
    if(mat==NULL){
        printf("Erro na locacao da matriz");
        return 1;
    }

    for(int i=0;i<coluna;i++){
        mat[i]=(int *)malloc(coluna*sizeof(int));
        if(mat==NULL){
            printf("Erro na locacao da matriz");
            return 1;
        }
    }

    preencher(mat,linha,coluna);
    if(comparar(mat,linha,coluna,N)==1){
        printf("O numero %d esta na matriz!", N);
    }else{
        printf("O numero %d nao esta na matriz!", N);
    }

    free(mat);
    return 0;
}