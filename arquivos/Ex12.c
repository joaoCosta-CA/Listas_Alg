#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 31 

FILE *abrirArquivo(const char *nome, const char *modo)
{
    FILE *arq = fopen(nome, modo);
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    return arq;
}

int contarLinhas(FILE *arq)
{
    int linhas = 0;
    char buffer[TAM_LINHA];
    while (fgets(buffer, TAM_LINHA, arq) != NULL)
    {
        linhas++;
    }
    rewind(arq);
    return linhas;
}

char **lerLinhas(FILE *arq, int totalLinhas)
{
    char **linhas = malloc(totalLinhas * sizeof(char *));
    if (linhas == NULL)
    {
        printf("Erro de alocação\n");
        exit(1);
    }

    for (int i = 0; i < totalLinhas; i++)
    {
        linhas[i] = malloc(TAM_LINHA * sizeof(char));
        if (linhas[i] == NULL)
        {
            printf("Erro de alocação\n");
            exit(1);
        }
        fgets(linhas[i], TAM_LINHA, arq);
        linhas[i][strcspn(linhas[i], "\n")] = '\0';
    }
    return linhas;
}

void inverterLinha(char *linha)
{
    int i = 0, j = strlen(linha) - 1;
    while (i < j)
    {
        char tmp = linha[i];
        linha[i] = linha[j];
        linha[j] = tmp;
        i++;
        j--;
    }
}

void escreverLinhasInvertidas(FILE *arq, char **linhas, int totalLinhas)
{
    for (int i = totalLinhas - 1; i >= 0; i--)
    {
        inverterLinha(linhas[i]);
        fprintf(arq, "%s\n", linhas[i]);
    }
}

void liberarMemoria(char **linhas, int totalLinhas)
{
    for (int i = 0; i < totalLinhas; i++)
    {
        free(linhas[i]);
    }
    free(linhas);
}

int main()
{
    char nomeEntrada[100], nomeSaida[100];

    printf("Nome do arquivo de entrada: ");
    scanf("%s", nomeEntrada);

    printf("Nome do arquivo de saída: ");
    scanf("%s", nomeSaida);

    FILE *entrada = abrirArquivo(nomeEntrada, "r");
    FILE *saida = abrirArquivo(nomeSaida, "w");

    int totalLinhas = contarLinhas(entrada);
    char **linhas = lerLinhas(entrada, totalLinhas);
    escreverLinhasInvertidas(saida, linhas, totalLinhas);
    liberarMemoria(linhas, totalLinhas);

    fclose(entrada);
    fclose(saida);

    printf("Arquivo gerado com sucesso!\n");
    return 0;
}