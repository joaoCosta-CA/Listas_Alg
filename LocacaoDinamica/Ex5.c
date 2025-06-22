#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int N){
    int *vet=(int *)calloc(N,sizeof(int));
    if(N<=0){
        return vet=NULL;
    }
    return vet;
}

int main(){
    int N=1;   
    if(alocarVetor(N)!=NULL){
        printf("O vetor foi alocado corretamente!");
    }else{
        printf("O alocamento deu errado, digite um numero maior que 0");
    }

    free(alocarVetor(N));

    return 0;
}