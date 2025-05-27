#include <stdio.h>

#define V 5
#define A 5

struct voos{
    int codorig;
    int coddest;

};

struct aero{
    char nome[20];
    int cod;
    int chegada;
    int sai;
};

int main(){
    struct voos v[V] = {
        {123, 789},
        {789, 333},
        {333, 910},
        {910, 246},
        {246, 123}
    };

    struct aero a[A]={
        {"NY",123,0,0},
        {"BR",789,0,0},
        {"CN",333,0,0},
        {"URSS",910,0,0},
        {"CH",246,0,0}
    };


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if (a[i].cod == v[j].coddest){
                a[i].chegada++;
                printf("Aero de %s recebe o voo de origem %d (teve %d voos recebidos)\n", a[i].nome, v[j].codorig, a[i].chegada);
            }
        }

    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if (a[i].cod == v[j].codorig){
                a[i].sai++;
                printf("%s teve %d voos que sairam(voo %d)\n", a[i].nome, a[i].sai, v[j].codorig);
            }
        }
    }
}