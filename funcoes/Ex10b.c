#include <stdio.h>

int jaexiste(int v[],int tamanho, int valor){
    for(int i=0;i<tamanho;i++){
        if(v[i]==valor){
            return 1;
        }
    }

    return 0;
}

int contadigitos(int a[], int b[],int tamA,int tamB){
   int cont=0;
   int v[10];
   int usadoscount=0;

   for(int i=0;i<tamA;i++){
        for(int j=0;j<tamB;j++){
            if(a[i]==b[j] && !jaexiste(v,usadoscount,a[i])){
                v[usadoscount++]=a[i];
                cont++;
                break;
            }
        }
   }

   return 0;
  
}

int main(){
    int a[10];
    int b[10];
    int vf,cont1=0,cont2=0;

    puts("Digite um valor inteiro(o maior):");
    for(int i=0;i<10;i++){
        scanf("%d", &a[i]);
        if(a[i]==0){
            break;
        }
        cont1++;
    }

    puts("Digite outro valor inteiro(o menor):");
    for(int i=0;i<10;i++){
        scanf("%d", &b[i]);
        if(b[i]==0){
            break;
        }
        cont2++;
    }

    vf=contadigitos(a,b,cont1,cont2);

    if(vf==0){
        for(int i=0;i<cont1;i++){
            printf("%d", a[i]);
        }

        printf(" tem como permutacao o valor ");

        for(int i =0;i<cont2;i++){
            printf("%d", b[i]);
        }
    }else{
        printf("Nao eh permutacao");
    }

}