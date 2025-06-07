#include <stdio.h>

double volume(double a, double b){
    double pi = 3.1414592;
    double v, square;
    square=a*a;
    v=pi*square*b;
    return v;
}

int main(){
    double altura,raio,vf;

    printf("Digte o valor da altura e do raio:\n");
    scanf("%lf %lf", &altura, &raio);

    vf=volume(raio,altura);

    printf("O volume do cilindro eh: %.2lf", vf);

    return 0;
}