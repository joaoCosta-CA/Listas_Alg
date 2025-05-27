#include <stdio.h>

int main(){
    int vet1[20], vet2[20], dif[20], soma[20], mult[20];

    printf("Digite 20 valores para o primeiro vetor:\n");
    for (int i = 0; i < 20; i++){
        scanf("%d", &vet1[i]);
    }

    printf("Digite mais 20 valores para o segundo vetor:\n");
    for (int j = 0; j < 20; j++){
        scanf("%d", &vet2[j]);
    }

    for (int k = 0; k < 20; k++){
        dif[k] = vet1[k] - vet2[k];
        soma[k] = vet1[k] + vet2[k];
        mult[k] = vet1[k] * vet2[k];
    }

    printf("============================================\n===========================================\n");

    printf("Soma= ");
    for (int l = 0; l < 20; l++){
        printf("[%d]", soma[l]);
    }

    printf("\n");

    printf("Diferenca= ");
    for (int m = 0; m < 20; m++){
        printf("[%d]", dif[m]);
    }

    printf("\n");

    printf("Multiplicacao= ");
    for (int n = 0; n < 20; n++){
        printf("[%d]", mult[n]);
    }
}
