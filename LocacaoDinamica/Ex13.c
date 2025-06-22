#include <stdio.h>
#include <stdlib.h>

void matrizTrans(int **NM, int N, int M){
    int **MN=malloc(M*sizeof(int *));
    if(MN==NULL){
        printf("Erro na locacao!");
        exit(1);
    }

    for(int i=0;i<M;i++){
        MN[i]=malloc(N*sizeof(int));
        if(MN[i]==NULL){
            printf("Erro na locacao!");
            exit(1);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            MN[j][i]=NM[i][j];
        }
    }


    printf("---- MATRIZ TRANSPOSTA ----\n");
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("[%d]", MN[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++){
        free(MN[i]);
    }
    free(MN);
}

void criarMatriz(int N, int M){
    int **NM=malloc(N*sizeof(int *));
    if(NM==NULL){
        printf("Erro na locacao!");
        exit(1);
    }

    for(int i=0;i<N;i++){
        NM[i]=malloc(M*sizeof(int));
        if(NM[i]==NULL){
            printf("Erro na locacao!");
            exit(1);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &NM[i][j]);
        }
    }

    printf("---- MATRIZ ----\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("[%d]", NM[i][j]);
        }
        printf("\n");
    }
    matrizTrans(NM,N,M);


    for(int i=0;i<N;i++){
        free(NM[i]);
    }
    free(NM);
}

int main(){
    int N,M;

    puts("Digite um numero N positivo");
    scanf("%d", &N);
    puts("Digite um numeor M");
    scanf("%d", &M);

    criarMatriz(N,M);
}
