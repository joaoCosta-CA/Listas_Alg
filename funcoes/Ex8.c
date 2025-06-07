#include <stdio.h>

int calcularDuracao(int h1, int m1, int h2, int m2){
    int inicio = h1 * 60 + m1;
    int fim = h2 * 60 + m2;

    if (fim < inicio){
        fim += 24 * 60; 
    }

    return fim - inicio;
}

int main(){
    int horaInicio, minInicio, horaFim, minFim;

    printf("Hora e minuto de início: ");
    scanf("%d %d", &horaInicio, &minInicio);

    printf("Hora e minuto de fim: ");
    scanf("%d %d", &horaFim, &minFim);

    int duracao = calcularDuracao(horaInicio, minInicio, horaFim, minFim);
    printf("Duração do jogo: %d minutos\n", duracao);

    return 0;
}