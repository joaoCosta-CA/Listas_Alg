#include <stdio.h>

int main(){
    int vet[3][3], soma=0, s[3];

    printf("Digite os valores para o vetor:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &vet[i][j]);
        }
    }

    for(int j=0;j<3;j++){
        soma=0;
        for(int i=0;i<3;i++){
            soma +=vet[i][j];
        }
        s[j] = soma;
    }

    printf("Matriz principal:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("[%d]", vet[i][j]);
        }
        printf("\n");
    }

    printf("Vetor das somas:\n");
    for(int i=0;i<3;i++){
        printf("[%d]", s[i]);
    }


}