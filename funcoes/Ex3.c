#include <stdio.h>

int media(int a, int b, int c, int d){
    int med;
    if (d == 'A'){
        med = (a + b + c) / 3;
        return med;
    }
    else if (d == 'P'){
        med = (a+b+c)/(5+3+2);
    }
    
    return med;
}

int main(){
    int n1, n2, n3, vf;
    char met;

    puts("Digite os valores das notas:");
    scanf("%d %d %d", &n1,&n2,&n3);
    puts("Digite como deseja calcular a media(A ou P):");
    getchar();
    scanf("%c", &met);

    vf=media(n1, n2, n3, met);

    printf("A media ficou:\n%d", vf);
}