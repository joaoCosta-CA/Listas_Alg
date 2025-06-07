#include <stdio.h>
#include <math.h>

void mover(int origem, int destino){
    printf("Mover disco de %d para %d\n", origem, destino);
}

int main(){
    int n;
    scanf("%d", &n);

    int total = pow(2, n);
    int origem = 0, destino = 2, auxiliar = 1;

    if (n % 2 == 0){
        int temp = destino;
        destino = auxiliar;
        auxiliar = temp;
    }

    for (int i = 1; i < total; i++){
        if (i % 3 == 1)
            mover(origem, destino);
        else if (i % 3 == 2)
            mover(origem, auxiliar);
        else
            mover(auxiliar, destino);
    }

    return 0;
}