#include <stdio.h>
#include <math.h>
struct psuperioresq{
    double x;
    double y;
};

struct pinferiordir{
    double x;
    double y;
};

struct retangulo{
    struct psuperioresq psesq;
    struct pinferiordir pinfd;
    
};

int main(){
    struct retangulo c1, c2;
    double decX=0, decY=0, quad=0;
    double area, perim;

    printf("Digite o valor do primeiro X e Y:\n");
    scanf("%lf", &c1.psesq.x);
    scanf("%lf", &c1.psesq.y);

    printf("Digite os valores do segundo X e Y:\n");
    scanf("%lf",&c2.pinfd.x);
    scanf("%lf", &c2.pinfd.y);

    decX= c1.psesq.x-c2.pinfd.x;
    decY= c1.psesq.y-c2.pinfd.y;
    if (decX <0){
        decX = decX * -1;
 
    }
    if(decY<0){
        decY = decY * -1;
    }

    area=decX*decY;
    perim=(decX*2)+(decY*2);
    decX= decX*decX;
    decY= decY*decY;
    quad=decX+decY;
    quad=sqrt(quad);

    printf("A diagona eh: %.1lf", quad);
    printf("\n");
    printf("A area eh %.1lf", area);
    printf("\n");
    printf("O perimetro eh: %.1lf", perim);



}