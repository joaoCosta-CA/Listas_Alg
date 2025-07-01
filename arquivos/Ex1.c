#include <stdio.h>
#include <stdlib.h>

void gravar(int binario[], int cont){
    FILE *fp = fopen("arquivo.txt", "ab"); 
    if (fp == NULL){
        puts("Erro ao abrir o arquivo");
        exit(1);
    }

    for (int i = cont - 1; i >= 0; i--){ 
        fprintf(fp, "%d", binario[i]);
    }
    fprintf(fp, "\n"); 

    fclose(fp);
}

void decimalParaBinario(int num){
    if (num == 0){
        int zero = 0;
        gravar(&zero, 1);
        return;
    }

    int binario[32];
    int i = 0;

    while (num > 0){
        binario[i++] = num % 2;
        num = num / 2;
    }

    gravar(binario, i);
}

int Escrever(int *vet){
    puts("Digite os valores do vetor (negativo para parar):");

    int i;
    for (i = 0; i < 30; i++){
        scanf("%d", &vet[i]);
        if (vet[i] < 0){
            break;
        }
    }
    return i;
}

void Excluir(){
    int op;

    puts("Deseja excluir o arquivo? (1-Sim / 0-Nao)");
    scanf("%d", &op);

    if (op == 1){
        int exclude = remove("arquivo.txt");
        if (exclude != 0){
            puts("Erro na remocao do arquivo");
            exit(1);
        }else{
            puts("Removido com sucesso");
        }
    }
}

int main(){
    int *vet = (int *)malloc(30 * sizeof(int));
    if (vet == NULL){
        puts("Erro de alocacao");
        return 1;
    }

    int qtd = Escrever(vet);

    for (int i = 0; i < qtd; i++){
        if (vet[i] >= 0){
            decimalParaBinario(vet[i]);
        }
    }

    free(vet);
    Excluir();

    return 0;
}