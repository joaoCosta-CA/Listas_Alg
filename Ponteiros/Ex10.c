#include <stdio.h>

void calcular(int a, int*b,int **c, int ***d){
    *b=*b*2;
    printf("Dobro = %d\n", *b);
    **c=**c+a;
    printf("Triplo = %d\n", **c);
    ***d=***d+a;
    printf("Quadruplo = %d", ***d);
}

int main(){
    int a,*b,**c,***d;

    puts("Digite um valor:");
    scanf("%d", &a);

    b=&a;
    c=&b;
    d=&c;
    calcular(a,b,c,d);
}