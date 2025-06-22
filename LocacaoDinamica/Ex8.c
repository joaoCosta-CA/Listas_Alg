#include <stdio.h>
#include <stdlib.h>

int* vetorB(int **vet, int n, int n2){
    int *vetB=(int *)malloc(n*sizeof(int));
    *vetB=0;

    for(int i=0;i<n;i++){
        *(vetB+i)=0;
        for(int j=0;j<n2;j++){
            *(vetB+i)+=vet[j][i];
        }
    }
    return vetB;

    free(vetB);
}

int** preencher(int n,int n2){
    int** vet=malloc(n*sizeof(int));

    if(vet==NULL){
        printf("Erro na locacao");
        exit(1);
    }

    for(int i=0;i<n;i++){
        vet[i]=malloc(n2*sizeof(int));
        if(vet[i]==NULL){
            printf("Erro na locacao");
            exit(1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n2;j++){
            scanf("%d", &vet[i][j]);
        }

    }

    return vet;

    for(int i=0;i<n;i++){
        free(vet[i]);
    }
    free(vet);
}

int main(){
    int N1,N2;

    printf("Digite o numero de linhas e de colnas da matriz:");
    scanf("%d", &N1);
    N2=N1;

    int **Vet =preencher(N1,N2);


    printf("------- Matriz inicial ---------------");
    printf("\n");
    for(int i=0;i<N1;i++){
        for(int j=0;j<N2;j++){
            printf("[%d]", Vet[i][j]);
        }
        printf("\n");
    }

    int *vetB=vetorB(Vet,N1,N2);
    
    printf("------- Vetor criado ------------");
    printf("\n");
    for(int i=0;i<N1;i++){
        printf("[%d]", *(vetB+i));
    }

    free(vetB);
    for (int i = 0; i < N1; i++){
        free(Vet[i]);
    }
    free(Vet);

    return 0;

}