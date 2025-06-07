#include <stdio.h>
#include <math.h>

int arredondar(float a){
    double decimal = fmod(a,1),numero;
    if(decimal>=0.5){
        numero=a-decimal;
        numero=numero+1;
    }else if(decimal<0.5){
        numero=a-decimal;
    }

    return numero;
    
}

int main(){
    float n;
    int vf;
    puts("Digite um valor positivo com ponto flutuante:");
    scanf("%f", &n);

    vf=arredondar(n);

    printf("O numero %.2lf arrendondado fica %d", n, vf);

    return 0;
}