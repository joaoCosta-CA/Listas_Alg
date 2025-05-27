#include <stdio.h>

int main(){
    int vet[4][3][3], soma=0;

    printf("Digite os valores da matriz:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                scanf("%d", &vet[i][j][k]);
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                soma+=vet[i][j][k];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                printf("[%d]", vet[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

}