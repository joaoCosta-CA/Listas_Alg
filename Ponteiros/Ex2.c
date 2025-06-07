#include <stdio.h>

int main(){
    int n1,n2;
    int *p1,*p2;

    puts("Digite um valor para n1:");
    scanf("%d", &n1);
    puts("Digite um valor para n2:");
    scanf("%d", &n2);

    p1=&n1;
    p2=&n2;

    if(p1>p2){
        printf("O valor do maior endereco = %d", *p1);
    }else{
        printf("O valor do maior enderceo = %d", *p2);
    }
}