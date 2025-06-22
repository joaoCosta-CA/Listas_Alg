#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){
    printf("Digite os %d números da sua aposta (0-100):\n", n);
    for (int i = 0; i < n; i++){
        printf("Número %d: ", i + 1);
        scanf("%d", &aposta[i]);

        while (aposta[i] < 0 || aposta[i] > 100){
            printf("Número inválido! Digite um valor entre 0 e 100: ");
            scanf("%d", &aposta[i]);
        }
    }
}

void sorteia_valores(int *sorteio, int n){
    for (int i = 0; i < n; i++){
        sorteio[i] = rand() % 101;
    }
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
    *qtdacertos = 0;

    for (int i = 0; i < na; i++){
        for (int j = 0; j < ns; j++){
            if (aposta[i] == sorteio[j]){
                (*qtdacertos)++;
                break;
            }
        }
    }

    int *acertos = (int *)malloc((*qtdacertos) * sizeof(int));
    if (acertos == NULL){
        printf("Erro ao alocar memória para os acertos!\n");
        *qtdacertos = 0;
        return NULL;
    }

    int pos = 0;
    for (int i = 0; i < na; i++){
        for (int j = 0; j < ns; j++){
            if (aposta[i] == sorteio[j]){
                acertos[pos] = aposta[i];
                pos++;
                break;
            }
        }
    }

    return acertos;
}

int main(){
    int qtd_aposta, qtd_acertos = 0;
    int *aposta = NULL, *sorteio = NULL, *acertos = NULL;

    srand(time(NULL));

    printf("BINGO DE PROG II\n");
    printf("Quantos números você deseja apostar (1-20)? ");
    scanf("%d", &qtd_aposta);

    while (qtd_aposta < 1 || qtd_aposta > 20){
        printf("Quantidade inválida! Digite um valor entre 1 e 20: ");
        scanf("%d", &qtd_aposta);
    }

    aposta = (int *)malloc(qtd_aposta * sizeof(int));
    if (aposta == NULL){
        printf("Erro ao alocar memória para a aposta!\n");
        return 1;
    }

    ler_aposta(aposta, qtd_aposta);

    sorteio = (int *)malloc(20 * sizeof(int));
    if (sorteio == NULL){
        printf("Erro ao alocar memória para o sorteio!\n");
        free(aposta);
        return 1;
    }
    sorteia_valores(sorteio, 20);

    acertos = compara_aposta(aposta, sorteio, &qtd_acertos, qtd_aposta, 20);

    printf("\nNúmeros sorteados: ");
    for (int i = 0; i < 20; i++){
        printf("%d ", sorteio[i]);
    }

    printf("\n\nVocê acertou %d número(s): ", qtd_acertos);
    for (int i = 0; i < qtd_acertos; i++){
        printf("%d ", acertos[i]);
    }
    printf("\n");

    free(aposta);
    free(sorteio);
    free(acertos);

    return 0;
}