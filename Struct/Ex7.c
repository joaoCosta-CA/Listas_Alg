#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct cartas{
    char naipe[20];
    char valor[13];
};

int main(){
    struct cartas baralho[52];
    char valor[13][4] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    char naipe[4][20] = {"de ouros","de espadas","de copas","de paus"};
    char valor_cartas[5], valor_cartas2[5];
    char naipe_cartas[5], naipe_cartas2[5];
   

    int k=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            strcpy(baralho[k].valor, valor[j]);
            strcpy(baralho[k].naipe, naipe[i]);
            k++;
        } 
    }
    srand(time(NULL));

    for(int i=0;i<5;i++){
     valor_cartas[i]=rand()%13;
     valor_cartas2[i]=rand()%13;
     naipe_cartas[i]=rand()%4;
     naipe_cartas2[i]=rand()%4;
    }


    printf("Jogador:1\n");
    for(int i=0;i<5;i++){
        printf("%s %s\n", valor[valor_cartas[i]], naipe[naipe_cartas[i]]);
    }

    printf("\n");
    printf("Jogador:2\n");
    for(int i=0;i<5;i++){
        printf("%s %s\n", valor[valor_cartas2[i]], naipe[naipe_cartas2[i]]);;
    }

    
}