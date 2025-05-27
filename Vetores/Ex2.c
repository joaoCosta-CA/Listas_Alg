#include <stdio.h>

int main(){
    int vet1[5]={0}, vet2[5]={0}, vetx[5]={0}, t=0;

    printf("Digite 5 valores do rpiemeiro vetor:\n");
    for(int i=0;i<5;i++){
        scanf("%d", &vet1[i]);
    }

    printf("Digite mais 5 valores para o segndo  vetor:\n");
    for(int j=0;j<5;j++){
        scanf("%d", &vet2[j]);
    }

    for(int k=0;k<5;k++){
        for(int l=0;l<5;l++){
            if(vet1[k]==vet2[l]){
                vetx[l]=vet1[k];
                t++;
            }
        }
    }

    printf("Valores iguais:\n");
    for(int m=0;m<t;m++){
        printf("[%d]\n", vetx[m]);
    }
}