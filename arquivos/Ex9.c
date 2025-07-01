#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float nota1, nota2, nota3;
    float media;
    int aprovado;

}Aluno;

void aprovados(Aluno *alunos, int tamanho){  
    for(int i=0;i<tamanho;i++){
        if(alunos[i].aprovado==1){
            printf("%s, aprovado!\n", alunos[i].nome);
        }
    }
}

void reprovados(Aluno *alunos, int tamanho){
    for(int i=0;i<tamanho;i++){
        if(alunos[i].aprovado==0){
            printf("%s, reprovado!", alunos[i].nome);
        }
    }
}

void insecNotas(Aluno *alunos, int tamanho){
    for(int i=0;i<tamanho;i++){
        puts("Nome:");
        setbuf(stdin,NULL);
        fgets(alunos[i].nome,50,stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';


        scanf("%f", &alunos[i].nota1);
        scanf("%f", &alunos[i].nota2);
        scanf("%f", &alunos[i].nota3);

    }
}

void alunoMed(Aluno *alunos, int tamanho){
    for(int i=0;i<tamanho;i++){
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;

        if (alunos[i].media >= 6.0){
            alunos[i].aprovado=1;
        }

        printf("Aluno: %s\n", alunos[i].nome);
        printf("Media: %.2f\n", alunos[i].media);
    }
}

int  exibirMenu(){
    printf("(1) - Definir informacoes da turma\n");
    printf("(2) - Inserir alunos e notas(Maximo 3 notas)\n");
    printf("(3) - Exibir alunos e medias\n");
    printf("(4) - Exibir alunos aprovados\n");
    printf("(5) - Exibir alunos reprovados\n");
    printf("(6) - Salvar dados em disco\n");
    printf("(7) - Sair do programa\n");
    int op;
    scanf("%d", &op);

    return op;
}

void salvarDados(Aluno *alunos, int tamanho, FILE *arq){
    for(int i=0;i<tamanho;i++){
        fprintf(arq,"Nome: %s Notas: %.2f, %.2f, %.2f Media: %.2f\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].media);
    }
    fclose(arq);
    puts("Arquivo salvo com sucesso");
}

int main(){
    int escolha;
    FILE *arq=fopen("ListaAlunos.txt", "w");
    if(arq==NULL){
        puts("Erro ao abrir o arquivo");
        return 1;
    }

    int tamanho=10;
    Aluno *alunos=(Aluno *)malloc(tamanho*sizeof(Aluno));
    if(alunos==NULL){
        perror("Erro na locacao");
        return 1;
    }



    do{
        escolha = exibirMenu();

        switch (escolha){
        case 1:
            
            break;
        case 2:
            insecNotas(alunos,tamanho);
            break;
        case 3:
            alunoMed(alunos,tamanho);
            break;
        case 4:
            aprovados(alunos,tamanho);
            break;
        case 5:
            reprovados(alunos,tamanho);
            break;
        case 6:
            salvarDados(alunos,tamanho,arq);
            break;
        case 7:
            puts("Programa finalizado!");
            return 0;
        default:
            puts("Numero invalido!");
            break;
        }
    }while(escolha != 7);

    free(alunos);
    return 0;
}