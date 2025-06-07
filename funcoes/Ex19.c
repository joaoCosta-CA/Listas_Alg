#include <stdio.h>

void hanoi(int n, int origem, int destino, int auxiliar){
    if (n == 1){
        printf("Mover disco de %d para %d\n", origem, destino);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco de %d para %d\n", origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 0, 2, 1);
    return 0;
}