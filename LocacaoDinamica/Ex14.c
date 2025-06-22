#include <stdio.h>
#include <stdlib.h>

void alocarVetor(){
    int N=10, cont=0;
    int *vetor = (int *)calloc(N,sizeof(int));

    puts("Digite 0 para parar");
    for(int i=0;i<N;i++){
        scanf("%d", &vetor[i]);
        if(vetor[i]==0){
            break;
        }
        cont++;
        if(cont==N){
            N+=10;
            vetor=(int *)realloc(vetor,N*sizeof(int));
        }
    }

    printf("%d", cont);
    printf("\n");
    for(int i=0;i<cont;i++){
        printf("[%d]", vetor[i]);
    }

    free(vetor);
}

int main(){
    alocarVetor();

}