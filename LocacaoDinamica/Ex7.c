#include <stdio.h>
#include <stdlib.h>

 int* alocarMemoria(int N, int N2){
    int *Vetor = (int *)malloc(N * sizeof(int));

    if(N<=0){
       return Vetor=NULL;
       exit(1);
    }else{
        for (int i = 0; i < N; i++){
            Vetor[i] = N2;
        }
    }
    
    return Vetor;
    
}

int main(){
    int n;
    int N1;

    printf("Qual o tamanho do vetor:");
    scanf("%d", &n);
    printf("Valor para preencher:");
    scanf("%d", &N1);
    
    int *p=alocarMemoria(n,N1);

    if(p==NULL){
        printf("Coloque um valor maior que 0 para o vetor");
    }else{
        for(int i=0;i<n;i++){
            printf("[%d]", *(p+i));
        }
    }
    
    free(p);
    return 0;
}