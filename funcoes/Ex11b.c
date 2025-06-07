#include <stdio.h>

int ehSegmento(int maior[], int menor[], int tamMaior, int tamMenor){
    for (int i = 0; i <= tamMaior - tamMenor; i++){
        int achou = 1;
        for (int j = 0; j < tamMenor; j++){
            if (maior[i + j] != menor[j]){
                achou = 0;
                break;
            }
        }
        if (achou){
            return 1; 
        }
    }
    return 0;
}

int main()
{
    int a[10],b[10], cont=0, cont2=0;

    puts("Digite um valor inteiro");
    for(int i=0;i<10;i++){
        scanf("%d", &a[i]);
        if(a[i]==0){
            break;
        }
        cont++;
    }

    puts("Digite um segundo valor inteiro");
    for(int i=0;i<10;i++){
        scanf("%d", &b[i]);
        if(b[i]==0){
            break;
        }
        cont2++;
    }

    if (ehSegmento(a, b, cont, cont2)){
        printf("B eh segmento de A\n");
    }
    else if (ehSegmento(b, a, cont2, cont)){
        printf("A eh segmento de B\n");
    }
    else{
        printf("Nenhum dos vetores eh segmento do outro\n");
    }

    return 0;
}