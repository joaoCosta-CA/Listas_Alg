#include <stdio.h>

int MenorValor(int a[],int inicio, int fim){
    if(fim==inicio)return a[inicio];
    
   int MenorResto= MenorValor(a, inicio+1, fim);
   if(a[inicio]<MenorResto){
        return a[inicio];
   }else{
    return MenorResto;
   }

}


int main(){
    int v[10];
    int cont=0;
    int vf;

    puts("Digite os valores para o vetor");
    for(int i=0;i<10;i++){
        int temp;
        scanf("%d", &temp);
        if(temp== -1)break;
        v[i]=temp;
        cont++;
    }

    vf=MenorValor(v,0,cont);
    printf("%d", vf);

    return 0;
}