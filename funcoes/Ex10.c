#include <stdio.h>

int contadigitos(int a[], int b){
    int cont=0;

    for(int i=0;a[i]!='\0';i++){
        if(b==a[i]){
            cont++;
        }
    }

    return cont;
}

int main(){
 int n[10];
 int d, cont=0;
 int vf;

 puts("Digite um valor inteiro:");
 for (int i=0;i<10; i++){
     scanf("%d", &n[i]);
     cont++;
     if(n[i]==0){
        cont--;
        break;
     }
 }

 puts("Digite um valor entre 1 e 8");
 scanf("%d", &d);

 vf=contadigitos(n,d);

 printf("%d apareceu %d vezes em ", d,vf);
 for(int i=0;i<cont;i++){
    printf("%d", n[i]);
 }
    
}