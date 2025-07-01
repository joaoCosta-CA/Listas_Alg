#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_ALFABETO 26

FILE *abrirArquivo(const char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        exit(1);
    }
    return arq;
}

void contarLetras(FILE *arq, int *frequencia){
    char c;
    while ((c = fgetc(arq)) != EOF){
        if (isalpha((unsigned char)c)){
            c = tolower(c);
            if (c >= 'a' && c <= 'z')
            {
                frequencia[c - 'a']++;
            }
        }
    }
}

void exibirFrequencia(const int *frequencia){
    printf("\nFrequência das letras no arquivo:\n");
    for (int i = 0; i < TAM_ALFABETO; i++){
        printf("%c: %d\n", 'a' + i, frequencia[i]);
    }
}

int main(){
    char nomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    int *frequencia = (int *)calloc(TAM_ALFABETO, sizeof(int));
    if (frequencia == NULL){
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    FILE *arq = abrirArquivo(nomeArquivo);
    contarLetras(arq, frequencia);
    fclose(arq);

    exibirFrequencia(frequencia);

    free(frequencia);
    return 0;
}