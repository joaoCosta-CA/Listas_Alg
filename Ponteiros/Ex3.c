#include <stdio.h>

void trocarValores(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;

    printf("\nValores apos a troca:\na=%d\nb=%d", *a,*b);
}

int main(){
    int a,b;
    int *Pa,*Pb;

    puts("Digiteum valor para a:");
    scanf("%d", &a);
    puts("Digite um valor para b");
    scanf("%d", &b);

    printf("Valores iniciais de:\na=%d\nb=%d", a,b);
    
    Pa=&a;
    Pb=&b;

    trocarValores(Pa,Pb);
    
}