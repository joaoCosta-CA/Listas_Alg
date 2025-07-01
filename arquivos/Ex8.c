#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencherMatriz(int **matriz,int linhas, int colunas){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}
void criarArquivo(int **matriz,int linhas, int colunas, FILE *arqMatriz){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            fprintf(arqMatriz,"[%d]", matriz[i][j]);
        }
        fprintf(arqMatriz,"\n");
    }

    printf("Arquivo criado com sucesso");
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
    int linha,colunas;
    scanf("%d", &linha);
    scanf("%d", &colunas);

    FILE *arqMatriz=fopen("Matriz.txt", "w");
    if(arqMatriz==NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    int **matriz=malloc(linha*sizeof(int));
    if(matriz==NULL){
        perror("Erro na locacao da memória");
        return 1;
    }

    for(int i=0;i<linha;i++){
        matriz[i]=malloc(colunas*sizeof(int));
        if(matriz[i]==NULL){
            perror("Erro de locacao");
            return 1;
        }
    }

    preencherMatriz(matriz,linha,colunas);
    criarArquivo(matriz,linha,colunas,arqMatriz);
    fclose(arqMatriz);
    excluir();

    for(int i=0;i<linha;i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}