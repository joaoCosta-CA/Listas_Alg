#include <stdio.h>

int main(){
    float vet[10] = {0};
    float a;

    printf("Digite 5 valores:\n");

    for (int i = 0; i < 10; i++){
        scanf("%f", &vet[i]);

        for (int j = 0; j < i; j++){
            if (vet[j] > vet[j + 1]){
                a = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = a;
            }
        }
    }

    for (int k = 0; k < 10; k++){
        printf("%.2f\n", vet[k]);
    }
}
