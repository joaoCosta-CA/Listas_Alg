#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char esporte[50];
    int idade;
    int altura;
}Atleta;

void LerAtletas(FILE *arq, Atleta lista[]){
    for(int i=0;i<3;i++){

        puts("Nome:");
        fgets(lista[i].nome,50,stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

        puts("Esporte praticante:");
        fgets(lista[i].esporte,50,stdin);
        lista[i].esporte[strcspn(lista[i].esporte, "\n")] = '\0';

        puts("Idade:");
        scanf("%d", &lista[i].idade);

        puts("Altura:");
        scanf("%d", &lista[i].altura);

        while (getchar() != '\n');

        fprintf(arq, "%s %s %d %d\n", lista[i].nome, lista[i].esporte, lista[i].idade, lista[i].altura);
    }
}

void excluir()
{
    int exclude;
    int op;

    puts("Excluir arquivo? (1-Sim / 0-Nao)");
    scanf("%d", &op);
    if (op){
        exclude = remove("ListaAtletas.txt");
        if (exclude != 0){
            puts("Erro ao excluir");
            exit(1);
        }else{
            puts("Arquivo removido!");
        }
    }
}

int main(){
    Atleta lista[5];
    FILE *arq=fopen("ListaAtletas.txt", "w");

    LerAtletas(arq, lista);
    fclose(arq);
    excluir();
}