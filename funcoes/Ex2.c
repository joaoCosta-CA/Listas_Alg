#include <stdio.h>

int conv(int a,int b,int c){
    int conv,soma=0;
    conv=a*3600;
    soma+=conv;
    conv=b*60;
    soma+=conv;
    soma+=c;

    return soma;
}

int main(){
    int h,m,s,vf;

    printf("Digite que horas sao:\n");
    scanf("%d %d %d", &h,&m,&s);

    vf=conv(h,m,s);

    printf("A conversao de horas para minutos ficou:\n%d", vf);
    
    return 0;
}