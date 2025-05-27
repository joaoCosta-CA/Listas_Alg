#include <stdio.h>

int main(){
    int vet[4][4], vet2[4][4], mult[4][4], soma;

    printf("Digite os valores para o primeiro vetor:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet[i][j]);
        }
    }

    printf("Digite os valres para o segundo vetor:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet2[i][j]);
        }
    }

    printf("Vetor 1:\n");
    for (int i = 0;i<4;i++){
        for (int j =0;j<4;j++){
            printf("[%d]", vet[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Vetor 2:");
    for (int i = 0;i<4;i++){
        for (int j = 0;j<4;j++){
            printf("[%d]", vet2[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            soma=0;
            for(int k=0;k<4;k++){
                soma+=vet[i][k]*vet2[k][j];
            }
            mult[i][j]=soma;
        }
    }

    printf("\n");

    printf("Vetor final:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("[%d]", mult[i][j]);
        }
        printf("\n");
    }


}