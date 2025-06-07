#include <stdio.h>

void imprimir(int *p,int v[]){
    p=&v[0];
    int dobro[5];
    for(int i=0;i<5;i++){
        dobro[i]=p[i]*2;
    }

    for(int i=0;i<5;i++){
        printf("[%d]", dobro[i]);
    }
}

int main(){
    int v[5];
    int *p;

    puts("Digite os valores para o vetor:");
    for(int i=0;i<5;i++){
        scanf("%d", &v[i]);
    }

    imprimir(p,v);
}