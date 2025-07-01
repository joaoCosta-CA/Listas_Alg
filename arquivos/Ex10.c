#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 31 

char **lerArquivo(const char *nomeArquivo, int *quantLinhas){
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq){
        perror("Erro ao abrir arquivo de entrada");
        exit(1);
    }

    char **linhas = NULL;
    char buffer[TAM_LINHA];
    *quantLinhas = 0;

    while (fgets(buffer, TAM_LINHA, arq)){
        linhas = realloc(linhas, (*quantLinhas + 1) * sizeof(char *));
        linhas[*quantLinhas] = malloc(TAM_LINHA);
        strcpy(linhas[*quantLinhas], buffer);
        (*quantLinhas)++;
    }

    fclose(arq);
    return linhas;
}

void inverterLinha(char *linha){
    int len = strlen(linha);

    if (linha[len - 1] == '\n'){
        linha[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len / 2; i++){
        char temp = linha[i];
        linha[i] = linha[len - 1 - i];
        linha[len - 1 - i] = temp;
    }
}

void inverterLinhas(char **linhas, int n){
    for (int i = 0; i < n; i++){
        inverterLinha(linhas[i]);
    }

    for (int i = 0; i < n / 2; i++){
        char *temp = linhas[i];
        linhas[i] = linhas[n - 1 - i];
        linhas[n - 1 - i] = temp;
    }
}

void escreverArquivo(const char *nomeArquivo, char **linhas, int n){
    FILE *arq = fopen(nomeArquivo, "w");
    if (!arq){
        perror("Erro ao abrir arquivo de saída");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        fprintf(arq, "%s\n", linhas[i]);
    }

    fclose(arq);
}

void liberarMemoria(char **linhas, int n){
    for (int i = 0; i < n; i++){
        free(linhas[i]);
    }
    free(linhas);
}

int main(){
    char nomeEntrada[100], nomeSaida[100];
    printf("Nome do arquivo de entrada: ");
    scanf("%s", nomeEntrada);

    printf("Nome do arquivo de saída: ");
    scanf("%s", nomeSaida);

    int totalLinhas = 0;
    char **linhas = lerArquivo(nomeEntrada, &totalLinhas);

    inverterLinhas(linhas, totalLinhas);

    escreverArquivo(nomeSaida, linhas, totalLinhas);

    liberarMemoria(linhas, totalLinhas);

    printf("Arquivo gerado com sucesso!\n");
    return 0;
}