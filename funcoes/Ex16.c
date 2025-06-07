#include <stdio.h>

void inverter(int a[], int inicio, int fim){
    if (inicio >= fim)return;

    int aux = a[inicio];
    a[inicio] = a[fim];
    a[fim] = aux;

    inverter(a, inicio + 1, fim - 1);
}


void imprimir(int a[], int cont){
    for (int i = 0; i < cont; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(){
    int v[10];
    int cont=0;

    puts("Digite um valor inteiro");
    for(int i=0;i<10;i++){
        scanf("%d", &v[i]);
        if(v[i]== -1)break;
        cont++;
    }

    inverter(v, 0, cont - 1); 

    imprimir(v, cont); 

    return 0;
}