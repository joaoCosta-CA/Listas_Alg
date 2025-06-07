#include <stdio.h>

double soma(int a[], int v){
    if(v==1){
        return a[0];
    }
    return a[v-1]+soma(a, v-1);
}

double media(int a[], int v){
    return soma(a,v)/v;
}

int main(){
    int vet[10];
    double vf;
    int cont=0;

    puts("Digite os valores para o vetor");
    for(int i=0;i<10;i++){
        scanf("%d", &vet[i]);
        if(vet[i]==0){
            break;
        }
        cont++;
    }

    vf=media(vet, cont);
    printf("Media = %.2f", vf);
}