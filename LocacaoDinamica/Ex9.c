#include <stdio.h>
#include <stdlib.h>

int **multiplicacao(int **a, int **b, int linhasA, int colunasA, int colunasB)
{
    int **c = malloc(linhasA * sizeof(int *));
    if (c == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }

    for (int i = 0; i < linhasA; i++)
    {
        c[i] = malloc(colunasB * sizeof(int));
        if (c[i] == NULL)
        {
            printf("Erro na alocação!\n");
            exit(1);
        }
    }

    for (int i = 0; i < linhasA; i++)
    {
        for (int j = 0; j < colunasB; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < colunasA; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;

    for(int i=0;i<linhasA;i++){
        free(c[i]);
    }
    free(c);
}

int main()
{
    int linha1, coluna1, linha2, coluna2;

    printf("Digite o numero de linhas da primeira matriz: ");
    scanf("%d", &linha1);
    printf("Digite o numero de colunas da primeira matriz: ");
    scanf("%d", &coluna1);
    printf("Digite o numero de linhas da segunda matriz: ");
    scanf("%d", &linha2);
    printf("Digite o numero de colunas da segunda matriz: ");
    scanf("%d", &coluna2);

    if (coluna1 != linha2)
    {
        printf("Nao eh possivel fazer a multiplicacao das matrizes!\n");
        return 1;
    }

    int **a = malloc(linha1 * sizeof(int *));
    for (int i = 0; i < linha1; i++)
    {
        a[i] = malloc(coluna1 * sizeof(int));
    }

    int **b = malloc(linha2 * sizeof(int *));
    for (int i = 0; i < linha2; i++)
    {
        b[i] = malloc(coluna2 * sizeof(int));
    }

    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < linha1; i++)
    {
        for (int j = 0; j < coluna1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < linha2; i++)
    {
        for (int j = 0; j < coluna2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int **Vf = multiplicacao(a, b, linha1, coluna1, coluna2);

    printf("Resultado da multiplicacao:\n");
    for (int i = 0; i < linha1; i++)
    {
        for (int j = 0; j < coluna2; j++)
        {
            printf("[%d]", Vf[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linha1; i++){
        free(a[i]);
    }
    free(a);
    for (int i = 0; i < linha2; i++){
        free(b[i]);
    }
    free(b);
    for (int i = 0; i < linha1; i++){
        free(Vf[i]);
    }
    free(Vf);

    return 0;
}
