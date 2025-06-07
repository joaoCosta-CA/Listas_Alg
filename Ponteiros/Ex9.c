#include <stdio.h>

void imprimir(int *p){

    for(int i=0;i<10;i++){
        printf("[%d]", *(p+i));
    }
}

int main(){
    int v[10];

    puts("Digite os valores para preencher o vetor");
    for(int i=0;i<10;i++){
        scanf("%d", v+i);
    }

    imprimir(v);
}