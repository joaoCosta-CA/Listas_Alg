#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[50];
    int dia;
    int mes;
    int ano;
}Datas;

void lerDatas(Datas lista[], FILE *arq){
    for(int i=0;i<2;i++){
        puts("Nome:");
        fgets(lista[i].nome,50,stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

        puts("Data de nascimento:");
        scanf(" %d %d %d", &lista[i].dia, &lista[i].mes, &lista[i].ano);

        fprintf(arq,"%s %d/%d/%d\n", lista[i].nome, lista[i].dia, lista[i].mes, lista[i].ano);
        setbuf(stdin, NULL);
    }
}

void calcularIdade(FILE *arq, FILE *arqData, Datas lista[]){
    int dia;
    int mes;
    int ano;
    int i=0;
    int idade;

    puts("Digite a data atual:");
    scanf("%d %d %d", &dia, &mes, &ano);

    while (fscanf(arq, "%s %d/%d/%d", lista[i].nome, &lista[i].dia, &lista[i].mes, &lista[i].ano)==4){
        idade=ano-lista[i].ano;
        printf("Lido: %s, %d/%d/%d\n", lista[i].nome, lista[i].dia, lista[i].mes, lista[i].ano);

        if (mes < lista[i].mes || (mes == lista[i].mes && dia < lista[i].dia)){
            idade--;
        }

        fprintf(arqData, "%s %d\n", lista[i].nome, idade);
        i++;
    }
}

void excluir(const char *nome){
    int exclude;
    int op;

    puts("Excluir arquivo? (1-Sim / 0-Nao)");
    scanf("%d", &op);
    if (op){
        exclude = remove(nome);
        if (exclude != 0){
            puts("Erro ao excluir");
            exit(1);
        }else{
            puts("Arquivo removido!");
        }
    }
}

int main(){
    Datas lista[2];
    const char *nomeArquivo="Datas.txt";
    FILE *arq=fopen(nomeArquivo, "w");
    if(arq==NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    lerDatas(lista, arq);
    fclose(arq);


    arq=fopen("Datas.txt", "r");
    if(arq==NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    const char *idadesLista="Idades.txt";
    FILE *arqData = fopen(idadesLista, "w");
    if(arqData==NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    calcularIdade(arq, arqData, lista);
    fclose(arqData);
    fclose(arq);
    excluir(nomeArquivo);
    excluir(idadesLista);

    return 0;
}