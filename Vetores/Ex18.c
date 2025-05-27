#include <stdio.h>

int main(){
    int mat[3][3], a;

    printf("Digite os valores da matriz:\n");
    for(int i=0;i<3;i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    printf("matriz 1:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            a=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=a;
        }
    }

    printf("matriz 2:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    }
