#include <stdio.h>

void somaDobro(int *a, int *b){
    *a*=2;
    *b*=2;

    int soma=*a+*b;

    printf("Soma do dobro de A e B = %d", soma);
}

int main(){
    int *a,*b;

    puts("Digite um valor para A:");
    scanf("%d", &*a);
    puts("Digite um valor para B:");
    scanf("%d", &*b);

    somaDobro(a,b);

}