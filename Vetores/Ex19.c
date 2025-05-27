#include <stdio.h>

int main(){
    float mat[3][6], somaimp=0,somap=0, med=0, soma6[3];

    printf("Digite os valores da matriz:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            scanf("%f", &mat[i][j]);
        }
    }

    printf("matriz 1:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("[%.1f]", mat[i][j]);
        }
        printf("\n");
    }

    for (int i =0; i<3; i++){
        for(int j=0;j<6;j++){
            if (j % 2 != 0){
                somaimp += mat[i][j];
            }
        }
    }

    printf("soma = %.1f\n", somaimp);

    printf("=======================================================================================\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            if(j==2 || j==4){
                somap+=mat[i][j];
            }
        }
    }
    med=somap/6;
    printf("Media aritimecia da coluna 2 e 4 = %f\n", med);

    printf("=======================================================================================");

    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            if(j==1){
                soma6[i]=mat[i][j]+mat[i][j+1];
            }
        }
    }


    printf("\n");

    printf("Soma das colunas 1 e 2:\n");
    for(int i=0;i<3;i++){
        printf("[%.1f]\n", soma6[i]);
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            if(j==5){
                mat[i][5]=soma6[i];
            }
        }
    }

    printf("\n");

    printf("Matriz modificada coma a soma da coluna 1 e 2:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("[%.1f]", mat[i][j]);
        }
        printf("\n");
    }

}