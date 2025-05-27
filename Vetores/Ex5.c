#include <stdio.h>

int main(){
    int vet1[10] = {0}, vet2[10] = {0}, insec[10] = {0}, v = 0, a = 0;

    printf("Digite 10 valores para o primeiro vetor:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &vet1[i]);
    }

    printf("Digite mais 10 valores para o segundo vetor:\n");
    for (int j = 0; j < 10; j++){
        scanf("%d", &vet2[j]);
    }

    for (int k = 0; k < 10; k++){
        for (int m = 0; m < 10; m++){
            if (vet1[k] == vet2[m]){
                v = 1;

                for (int n = 0; n < a; n++){
                    if (vet1[k] == insec[n]){
                        v = 0;
                    }
                }

                if (v != 0){
                    insec[k] = vet1[k];
                    a++;
                }
            }
        }
    }

    printf("Vetor Final:\n");
    for (int l = 0; l < 10; l++){
        if (insec[l] == 0){
            printf("");
        }
        else{
            printf("%d", insec[l]);
        }
    }
}
