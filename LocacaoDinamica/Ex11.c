#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void acertosLoteria(int loteriaAnoite[], int chuteLoteria[]){
    int acertos=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(chuteLoteria[i]==loteriaAnoite[j]){
                acertos++;
                break;
            }
        }
    }

    int *vf=(int *)malloc(acertos*sizeof(int));
    int k=0;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(chuteLoteria[i]==loteriaAnoite[j]){
                vf[k++]=chuteLoteria[i];
            }
        }
    }

    printf("----- Numeros Loteria ---------");
    printf("\n");
    for (int i = 0; i < 6; i++){
        printf("%d ", loteriaAnoite[i]);
    }
    printf("\n");
    printf("-------------------------------");
    printf("\n");

    printf("Numero de acertos: %d", acertos);
    printf("\n");
    for(int i=0;i<acertos;i++){
        printf("[%d]", vf[i]);
    }

}

int main(){
    int *loteriaAnoite=(int *)malloc(6*sizeof(int));
    srand(time(NULL));
    int *chuteLoteria=(int *)malloc(6*sizeof(int));

    for(int i=0;i<6;i++){
        (*(loteriaAnoite+i))=rand()%100;
    }
    puts("Digite os numeros para apostar na loteria");
    for(int i=0;i<6;i++){
        scanf("%d", &(*(chuteLoteria+i)));
    }

    acertosLoteria(loteriaAnoite, chuteLoteria);

    free(loteriaAnoite);
    free(chuteLoteria);

    return 0;
}