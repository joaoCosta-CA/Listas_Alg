#include <stdio.h>

void piramide(int a){
    int n=0;
    for(int i=0;i<a;i++){
        n++;
        for(int j=0;j<n;j++){
            printf("*");
        }
        printf("\n");

        if(n==a){
            for(int i=0;i<a;i++){
                n--;
                for(int j=0;j<n;j++){
                    printf("*");
                }
                printf("\n");
            }
        }
    }
}

int main(){
    int n;

    
    puts("Digite um valor para criar uma piramide:");
    scanf("%d", &n);
    printf("\n");

    piramide(n);
}