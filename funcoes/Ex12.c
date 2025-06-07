#include <stdio.h>
#include <math.h>

int cubo(int a, int v){

    if(v==1){
        return a;
    }else{
        return a * cubo(a, v - 1);
    }
}

int somaC(int n){
    int soma=0;

    for(int i=1;i<=n;i++){
        soma+=cubo(i,3);
    }

    return soma;
}

int main(){
    int a;
    int res;

    puts("Digite um valor");
    scanf("%d", &a);

    res=somaC(a);
    printf("Soma = %d", res);

}