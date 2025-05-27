#include <stdio.h>

int main(){
    int vet[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(j==i){
                vet[i][j]=1;
            }else{
                vet[i][j]=0;
            }
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("[%d]", vet[i][j]);
        }
        printf("\n");
    }

}
    