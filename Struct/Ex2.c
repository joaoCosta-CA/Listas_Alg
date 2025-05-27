#include <stdio.h>
#include <math.h>

    struct ponto{
        double x;
        double y;
    };

int main(){
    struct ponto c1, c2;
    double incX=0, incY=0, quad=0;

    printf("Digite um valor para X e Y do primeiro:\n");
    scanf("%lf", &c1.x);
    scanf("%lf", &c1.y);

    printf("Digite o valor de X e Y do segundo:\n");
    scanf("%lf", &c2.x);
    scanf("%lf", &c2.y);

    incX=c1.x-c2.x;
    incY=c1.y-c2.y;
    incX=incX*incX;
    incY=incY*incY;

    quad=incX+incY;
    quad=sqrt(quad);

    printf("A disttancia eh: %.1lf", quad);



}