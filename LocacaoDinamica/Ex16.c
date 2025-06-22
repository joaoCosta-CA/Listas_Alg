#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char nome[50];
    int x;
    int y;
} Cidade;

Cidade *ler_cidades(int N){
    Cidade *cidades = (Cidade *)malloc(N * sizeof(Cidade));
    if (cidades == NULL){
        printf("Erro ao alocar memória para cidades!\n");
        return NULL;
    }

    for (int i = 0; i < N; i++){
        printf("\nCidade %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", cidades[i].nome);
        printf("Coordenada X: ");
        scanf("%d", &cidades[i].x);
        printf("Coordenada Y: ");
        scanf("%d", &cidades[i].y);
    }
    return cidades;
}

double **calcular_matriz_distancias(Cidade *cidades, int N){
    double **distancias = (double **)malloc(N * sizeof(double *));
    if (distancias == NULL){
        printf("Erro ao alocar memória para matriz de distâncias!\n");
        return NULL;
    }

    for (int i = 0; i < N; i++){
        distancias[i] = (double *)malloc(N * sizeof(double));
        if (distancias[i] == NULL){
            printf("Erro ao alocar memória para linha da matriz!\n");
            for (int j = 0; j < i; j++){
                free(distancias[j]);
            }
            free(distancias);
            return NULL;
        }

        for (int j = 0; j < N; j++){
            if (i == j){
                distancias[i][j] = 0.0;
            }
            else{
                distancias[i][j] = sqrt(pow(cidades[j].x - cidades[i].x, 2) +
                                        pow(cidades[j].y - cidades[i].y, 2));
            }
        }
    }
    return distancias;
}

void exibir_matriz_distancias(double **distancias, Cidade *cidades, int N){
    printf("\nMatriz de Distâncias:\n");
    printf("%-15s", "");
    for (int i = 0; i < N; i++){
        printf("%-15s", cidades[i].nome);
    }
    printf("\n");

    for (int i = 0; i < N; i++){
        printf("%-15s", cidades[i].nome);
        for (int j = 0; j < N; j++){
            printf("%-15.2f", distancias[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz_distancias(double **distancias, int N){
    for (int i = 0; i < N; i++){
        free(distancias[i]);
    }
    free(distancias);
}

int main(){
    int N;
    Cidade *cidades;
    double **distancias;

    printf("Digite o número de cidades: ");
    scanf("%d", &N);

    cidades = ler_cidades(N);
    if (cidades == NULL){
        return 1;
    }

    distancias = calcular_matriz_distancias(cidades, N);
    if (distancias == NULL){
        free(cidades);
        return 1;
    }

    exibir_matriz_distancias(distancias, cidades, N);

    liberar_matriz_distancias(distancias, N);
    free(cidades);

    return 0;
}

