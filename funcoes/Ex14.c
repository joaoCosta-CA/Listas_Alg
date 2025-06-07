#include <stdio.h>

int elevado(int a, int y){
    int vf=0;
    if(y==0){
        return 1;
    }
    return vf+=a*elevado(a,y-1);
}

int main(){
    int x,y, vf;

    puts("Digite um valor para x");
    scanf("%d", &x);
    puts("Digite o valor de y");
    scanf("%d", &y);

    vf=elevado(x,y);
    printf("%d^%d = %d", x,y,vf);

    return 0;

}