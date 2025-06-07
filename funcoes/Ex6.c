#include <stdio.h>

int fatorial(int a){
    if(a==0){
        return 1;
    }
    return a*fatorial(a-1);
}

double neperiano(int a){
    double soma=0.0;
    for(int n=0;n<=a;n++){
        soma+=1.0/(fatorial(n));
    }

    return soma;
}

int main(){
    int N;
    double vf;

    puts("Digite o valor de N:");
    scanf("%d", &N);

    vf=neperiano(N);

    printf("e = %lf", vf);
}