#include <stdio.h>

int main(){
    int valorint=12, *pint;
    float valorfl=49.07, *pfloat;
    char letter='J', *pletter;

    printf("Endereco de pint = %p\n", pint);
    printf("Endereco de pfloat = %p\n", pfloat);
    printf("Enderceo de pletter = %p\n", pletter);

    printf("valorint =%d\n", valorint);
    printf("valorfl =%.2f\n", valorfl);
    printf("letter = %c\n", letter);

    pint=&valorint;
    pfloat=&valorfl;
    pletter=&letter;


    printf("Valores dos ponteiros apos serem atribuidos:\n");
    printf("*pint = %d\n", *pint);
    printf("*pfloat = %.2f\n", *pfloat);
    printf("*pletter = %c", *pletter);
    
}