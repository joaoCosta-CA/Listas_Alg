#include <stdio.h>
#include <math.h>

int main(){
    int vet[3][3];

    printf("Digite os valores do vetor:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &vet[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (i < j){
                vet[1][j] = (i*2)+(7*j)-2;
            }
            else if (i == j){
                vet[i][j] = (3*(sqrt(i)))-1;
            }
            else if (i > j){
                vet[i][j] = (4*(cbrt(i)))+(5*(sqrt(j)))+1;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("[%d]", vet[i][j]);
        }
        printf("\n");
    }
}