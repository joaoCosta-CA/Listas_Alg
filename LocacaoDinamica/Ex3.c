#include <stdio.h>
#include <stdlib.h>

void alocarMemoria(int N){
   int *Vetor=(int *)malloc(N*sizeof(int));

   for(int i=0;i<N;i++){
        printf("Preencha o vetor:");
        scanf("%d", &Vetor[i]);
   }

   printf("Vetor=");
   for(int i=0;i<N;i++){
    printf("[%d]", Vetor[i]);
   }

   free(Vetor);

}

int main(){
    int n;

    printf("Qual o tamanho do vetor?");
    scanf("%d", &n);

    if(n!=0){
        alocarMemoria(n);
    }else{
        printf("Digite um numero maior que 0");
    }

    return 0;
}