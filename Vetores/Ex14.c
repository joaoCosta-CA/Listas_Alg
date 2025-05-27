#include <stdio.h>

int main(){
    int vet[3][3], soma=0, somasec=0;

    printf("Digite os valores para o vetor:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &vet[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==i){
                soma+=vet[i][j];
            }
        }
    }

    printf("Soma da Diagonal principal= %d\n", soma);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0 && j==2 || i==1 && j==1 || i==2 && j==0){
                somasec+=vet[i][j];
            }
        }
    }

    printf("Soma da diagonal segindaria= %d", somasec);


}