#include <stdio.h>

void atribuir(int v[], int *p,int *p2,int cont){
    *p=v[0];
    *p2=v[0];
    for(int i=0;i<cont;i++){
        if(v[i]<*p){
            *p=v[i];
        }
        if(v[i]>*p2){
            *p2=v[i];
        }
    }

    printf("Menor valor = %d\nMaior valor = %d", *p,*p2);
}

int main(){
    int v[100];
    int *p,*p2;
    int cont=0; 
    puts("Digite os valores do vetor(-1 para sair):");
     for(int i=0;i<100;i++){
        int temp=0;
        scanf("%d", &temp);
        if(temp==-1)break;

        v[i]=temp;
        cont++;
     }

     atribuir(v,p,p2,cont);

}