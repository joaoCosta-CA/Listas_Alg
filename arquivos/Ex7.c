#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char esporte[50];
    int idade;
    int altura;
} Atleta;

void maisVelho(FILE *arq){
    Atleta atleta, maisVelho;
    int primeiro = 1;

    while (fread(&atleta, sizeof(Atleta), 1, arq) == 1){
        if (primeiro || atleta.idade > maisVelho.idade){
            maisVelho = atleta;
            primeiro = 0;
        }
    }

    if (!primeiro){
        printf("Atleta mais velho:\n");
        printf("Nome: %s\n", maisVelho.nome);
        printf("Idade: %d\n", maisVelho.idade);
    }else{
        printf("Arquivo vazio ou erro na leitura.\n");
    }
}

void maisAlto(FILE *arq){
    Atleta atleta, maisAlto;
    int primeiro=1;

    while(fread(&atleta,sizeof(Atleta),1,arq) == 1){
        if(primeiro || atleta.altura > maisAlto.altura){
            maisAlto=atleta;
            primeiro=0;
        }
    }

    if(!primeiro){
        printf("Atleta mais alto:\n");
        printf("Nome: %s\n", maisAlto.nome);
        printf("Altura: %dcm\n", maisAlto.altura);
    }else{
        printf("Arquivo vazio ou erro na leitura\n");
    }
}

void LerAtletas(FILE *arq, Atleta lista[]){
    for (int i = 0; i < 5; i++){

        puts("Nome:");
        fgets(lista[i].nome, 50, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

        puts("Esporte praticante:");
        fgets(lista[i].esporte, 50, stdin);
        lista[i].esporte[strcspn(lista[i].esporte, "\n")] = '\0';

        puts("Idade:");
        scanf("%d", &lista[i].idade);

        puts("Altura:");
        scanf("%d", &lista[i].altura);

        while (getchar() != '\n');

        fwrite(&lista[i],sizeof(Atleta),1,arq);
    }
}

void excluir(){
    int exclude;
    int op;

    puts("Excluir arquivo? (1-Sim / 0-Nao)");
    scanf("%d", &op);
    if (op){
        exclude = remove("ListaAtletas.bin");
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
    FILE *arq = fopen("ListaAtletas.bin", "wb");
    if(arq==NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    LerAtletas(arq, lista);
    fclose(arq);

    arq=fopen("ListaAtletas.bin", "rb");
    if(arq==NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    rewind(arq);
    maisVelho(arq);
    rewind(arq);
    maisAlto(arq);
    fclose(arq);
    excluir();
}