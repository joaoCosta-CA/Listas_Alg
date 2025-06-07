#include <stdio.h>

void mudarValor(int a, int v[]){
    int *p1;
    p1=&v[0];
    int *p2;
    p2=&a;

    for(int i=0;i<10;i++){
        p1[i]=*p2;
    }
    
    for(int i=0;i<10;i++){
        printf("[%d]", v[i]);
    }
}

int main(){
    int v[10];
    int valor;

    puts("Digite os valores para o vetor:");
    for(int i=0;i<10;i++){
        scanf("%d", &v[i]);
    }
    puts("Digit um valor para mudar no vetor:");
    scanf("%d", &valor);

    mudarValor(valor,v);
}