#include <stdio.h>

int main(){
    int vet[10];

    printf("Digite 10 valores(diferentes):\n");

    for (int i = 0; i < 10; i++){
        scanf("%d", &vet[i]);

        for (int j = 0; j < i; j++){
            if (vet[i] == vet[j]){

                int f = 0;
                while (f == 0){
                    printf("Digite um valor válido:\n");
                    scanf("%d", &vet[i]);
                    f = 1;

                    for (int k = 0; k < i; k++){
                        if (vet[i] == vet[k]){
                            f = 0;
                        }
                    }
                }
            }
        }
    }

    printf("Vetor final:");
    for (int l = 0; l < 10; l++){
        printf("%d", vet[l]);
    }
}
