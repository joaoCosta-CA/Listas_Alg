#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **criar_matriz_nomes(int max_nomes){
    char **matriz = (char **)calloc(max_nomes, sizeof(char *));
    if (matriz == NULL){
        printf("Erro ao alocar memória!\n");
    }
    return matriz;
}

void liberar_matriz_nomes(char **matriz, int max_nomes){
    for (int i = 0; i < max_nomes; i++){
        if (matriz[i] != NULL)
            free(matriz[i]);
    }
    free(matriz);
}

void gravar_nome(char **matriz, int max_nomes){
    int linha;
    char nome[31];

    printf("Digite o número da linha (0 a %d): ", max_nomes - 1);
    scanf("%d", &linha);
    getchar();

    if (linha < 0 || linha >= max_nomes){
        printf("Linha inválida!\n");
        return;
    }

    printf("Digite o nome (até 30 caracteres): ");
    fgets(nome, 31, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    if (matriz[linha] != NULL)
        free(matriz[linha]);

    matriz[linha] = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    if (matriz[linha] == NULL){
        printf("Erro ao alocar memória para o nome!\n");
        return;
    }
    strcpy(matriz[linha], nome);
    printf("Nome gravado com sucesso!\n");
}

void apagar_nome_linha(char **matriz, int max_nomes){
    int linha;

    printf("Digite o número da linha (0 a %d): ", max_nomes - 1);
    scanf("%d", &linha);
    getchar();

    if (linha < 0 || linha >= max_nomes){
        printf("Linha inválida!\n");
        return;
    }

    if (matriz[linha] != NULL){
        free(matriz[linha]);
        matriz[linha] = NULL;
        printf("Nome apagado com sucesso!\n");
    }
    else{
        printf("Linha já está vazia!\n");
    }
}

void procurar_substituir(char **matriz, int max_nomes){
    char nome[31], novo_nome[31];

    printf("Digite o nome a ser procurado: ");
    fgets(nome, 31, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o novo nome: ");
    fgets(novo_nome, 31, stdin);
    novo_nome[strcspn(novo_nome, "\n")] = '\0';

    for (int i = 0; i < max_nomes; i++){
        if (matriz[i] != NULL && strcmp(matriz[i], nome) == 0){
            free(matriz[i]);
            matriz[i] = (char *)malloc((strlen(novo_nome) + 1) * sizeof(char));
            strcpy(matriz[i], novo_nome);
            printf("Nome substituído na linha %d\n", i);
            return;
        }
    }
    printf("Nome não encontrado!\n");
}

void procurar_apagar(char **matriz, int max_nomes){
    char nome[31];

    printf("Digite o nome a ser procurado: ");
    fgets(nome, 31, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < max_nomes; i++){
        if (matriz[i] != NULL && strcmp(matriz[i], nome) == 0){
            free(matriz[i]);
            matriz[i] = NULL;
            printf("Nome apagado da linha %d\n", i);
            return;
        }
    }
    printf("Nome não encontrado!\n");
}

void exibir_menu(){
    printf("\nOpções:\n");
    printf("1 - Gravar um nome em uma linha\n");
    printf("2 - Apagar o nome de uma linha\n");
    printf("3 - Procurar e substituir um nome\n");
    printf("4 - Procurar e apagar um nome\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main(){
    int max_nomes, opcao;
    char **matriz;

    printf("Digite o número máximo de nomes: ");
    scanf("%d", &max_nomes);
    getchar();

    matriz = criar_matriz_nomes(max_nomes);
    if (matriz == NULL)
        return 1;

    do{
        exibir_menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
            case 1:
                gravar_nome(matriz, max_nomes);
                break;
            case 2:
                apagar_nome_linha(matriz, max_nomes);
                break;
            case 3:
                procurar_substituir(matriz, max_nomes);
                break;
            case 4:
                procurar_apagar(matriz, max_nomes);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    liberar_matriz_nomes(matriz, max_nomes);
    return 0;
}