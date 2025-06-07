#include <stdio.h>

int primo(int a){
    int n;
    for(int i=a;i>1;i--){
        if(a%i==0 && i%2!=0){
            n=i;
        }
    }
    return n;
}

int main(){
    int pri, vf;
    puts("Digite um numero:");
    scanf("%d", &pri);

    vf=primo(pri);

    printf("O maoir valor primo que %d eh divisivel eh %d", pri, vf);
}