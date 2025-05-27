#include <stdio.h>

int main()
{
    int n, vetn[100] = {0}, vetp[100] = {0}, veti[100] = {0};
    int a, t1 = 0, t2 = 0;

    printf("Digite quantos termos deseja:\n");
    scanf("%d", &n);

    printf("Digite os valores:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &vetn[i]);
    }

    for (int w = 0; w < n; w++){

        if (vetn[w] % 2 == 0){
            vetp[t1] = vetn[w];
            t1++;

            for (int j = 0; j < t1; j++){
                if (vetp[t1-1] < vetp[j]){
                    a = vetp[j];
                    vetp[j] = vetp[t1-1];
                    vetp[t1-1] = a;
                }
            }
        }
        else{
            veti[t2] = vetn[w];
            t2++;

            for (int k = 0; k < t2; k++)
            {
                if (veti[t2-1] > veti[k]){
                    a = veti[t2-1];
                    veti[t2-1] = veti[k];
                    veti[k] = a;
                }
            }
        }
    }

    printf("Pares:\n");
    for (int l = 0; l < t1; l++){
        printf("[%d]\n", vetp[l]);
    }

    printf("\nImpares:\n");
    for (int m = 0; m < t2; m++){
        printf("[%d]\n", veti[m]);
    }
}
