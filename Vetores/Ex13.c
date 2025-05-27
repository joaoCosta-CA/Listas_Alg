#include <stdio.h>

int main(){
    int vet[4][4], maior=0;

    printf("Digite os valores do vetor:\n");

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &vet[i][j]);
        }

    }


    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(vet[i][j]>10){
                maior++;
            }
        }
    }

    for (int i =0;i<4;i++){
        for (int j =0;j<4;j++){
            printf("[%d]", vet[i][j]);
        }
    }
    printf("\n");
    printf("Tem %d valores maiores que 10", maior);
}