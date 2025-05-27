#include <stdio.h>

struct aluno{
    int nota[3];
    float media;
    int matricula;
    char nome[20];
};

int main(){
    struct aluno v[5];
    int nota,matricula, soma=0;

    for(int i=0;i<3;i++){
        soma=0;
        printf("Matricula:%d\n", i+1);
        scanf("%d", &matricula);
        v[i].matricula=matricula;

        for(int j=0;j<3;j++){
            printf("Nota:%d\n", j+1);
            scanf("%d", &nota);
            v[i].nota[j] = nota;
            soma+=nota;
        }
        v[i].media = soma / 3;
    }

    float maior = v[0].media;
    int indice_maior = 0;

    for (int i =1;i<3;i++){
        if (v[i].media > maior){
            maior = v[i].media;
            indice_maior = i;
        }
    }

    printf("\nMaior media: %.1f (Aluno %d - Matricula %d)\n",
           maior, indice_maior + 1, v[indice_maior].matricula);

}